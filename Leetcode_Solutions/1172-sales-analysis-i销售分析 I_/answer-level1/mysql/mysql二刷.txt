```
SELECT a.seller_id
FROM (
	SELECT a.seller_id
		, CASE 
			WHEN a.amount = @preCol THEN @rank
			ELSE @rank := @rank + 1
		END AS rk, @preCol := a.amount
	FROM (
		SELECT a.seller_id, SUM(price) AS amount
		FROM Sales a
		GROUP BY a.seller_id
	) a, (
			SELECT @preCol := NULL, @rank := 0
		) s
	ORDER BY amount DESC
) a
WHERE a.rk = 1
```
