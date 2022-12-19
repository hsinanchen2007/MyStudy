
在本题中，offset 值相同的记录，其日期也相临。

```
select
	id, to_char(visit_date, 'yyyy-mm-dd') as visit_date, people
from
	(select
		id, visit_date, people,
		count(1) over (partition by offset) cnt
	from
		(select
			id, visit_date, people,
			(row_number() over (order by id) - id) offset
		from stadium
		where people >= 100
		)
	)
where cnt >= 3   -- 连续 3 天（及以上）
order by id
```
