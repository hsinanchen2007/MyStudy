思路很简单，首先根据每个用户每个时间的事务次数分组：
```
SELECT
			count( amount ) AS transactions_count,
			vi.user_id,
			vi.visit_date 
		FROM
			Visits vi
			LEFT JOIN TRANSACTIONs tr ON vi.user_id = tr.user_id 
			AND vi.visit_date = tr.transaction_date 
		GROUP BY
			vi.visit_date,
			vi.user_id 
```

之后找到事务发生次数的最大值和最小值：
```
SELECT
			@min := 0,
			@max := max( tmp.transactions_count ) 
		FROM
			(
			SELECT
				count( amount ) AS transactions_count 
			FROM
				Visits vi
				LEFT JOIN TRANSACTIONs tr ON vi.user_id = tr.user_id 
				AND vi.visit_date = tr.transaction_date 
			GROUP BY
				vi.visit_date,
				vi.user_id 
			) tmp 
```

之后，用这个最大值和最小值生成一组序列，让其从0到max即可。

需要注意的是，mysql里如果要生成序列，则可以让变量跟着一个辅助表，每查询一行+1这样来实现，这里一定要选用transactions表。

因为我们最终的排序是根据不同时间不同用户访问银行的次数来判定，只要根据transaction表来排序，则肯定能满足生成序列的要求，考虑极端情况：
假如transaction表中有一个用户在同一时间发生了36次事务，其他人没有，那么最大时36，我们需要生成0-36的序列，tran表中肯定有36行，我们就可以生成一个1-36的序列（注意没有0），然后再union一个0即可。

```
SELECT
		0 AS seq 
	FROM
	DUAL UNION
	SELECT
		CAST( @min AS SIGNED ) AS seq 
	FROM
		(
		SELECT
			@min := 0,
			@max := max( tmp.transactions_count ) 
		FROM
			(
			SELECT
				count( amount ) AS transactions_count 
			FROM
				Visits vi
				LEFT JOIN TRANSACTIONs tr ON vi.user_id = tr.user_id 
				AND vi.visit_date = tr.transaction_date 
			GROUP BY
				vi.visit_date,
				vi.user_id 
			) tmp 
		) final,
		Transactions tr 
	GROUP BY
	CASE
			
			WHEN @min < @max THEN
			@min := @min + 1 ELSE @max 
		END 
```
这里使用变量，在group的时候直接+1，实际上去重也是可以的，注意执行顺序，先group，然后再select，所以CAST( @min AS SIGNED ) AS seq这个是从1开始的。

有了序列，接下来就很好办了，直接左连接即可。
```
SELECT
	tmp1.seq AS transactions_count,
	count( concat( final.user_id, '|', final.visit_date ) ) AS visits_count 
FROM
	(
	SELECT
		0 AS seq 
	FROM
	DUAL UNION
	SELECT
		CAST( @min AS SIGNED ) AS seq 
	FROM
		(
		SELECT
			@min := 0,
			@max := max( tmp.transactions_count ) 
		FROM
			(
			SELECT
				count( amount ) AS transactions_count 
			FROM
				Visits vi
				LEFT JOIN TRANSACTIONs tr ON vi.user_id = tr.user_id 
				AND vi.visit_date = tr.transaction_date 
			GROUP BY
				vi.visit_date,
				vi.user_id 
			) tmp 
		) final,
		Transactions tr 
	GROUP BY
	CASE
			
			WHEN @min < @max THEN
			@min := @min + 1 ELSE @max 
		END 
		) tmp1
		LEFT JOIN (
		SELECT
			count( amount ) AS transactions_count,
			vi.user_id,
			vi.visit_date 
		FROM
			Visits vi
			LEFT JOIN TRANSACTIONs tr ON vi.user_id = tr.user_id 
			AND vi.visit_date = tr.transaction_date 
		GROUP BY
			vi.visit_date,
			vi.user_id 
		) final ON tmp1.seq = final.transactions_count 
GROUP BY
	tmp1.seq
```


