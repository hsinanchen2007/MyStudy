Oracle 写法：

题解
```sql
select 
	distinct Num as consecutiveNums
from
(
	select
		Num,
		(row_number() over (order by Id)
			-
			row_number() over (partition by Num order by Id)) lag
	from Logs
)
group by Num, lag
having count(1) >= 3;
```

自行在本地执行下述语句并观察结果（或者手写结果），就能发现相关规律：
```sql
select
	Id,
	Num,
	row_number() over (order by Id),
	row_number() over (partition by Num order by Id),
	row_number() over (order by Id)
		-
		row_number() over (partition by Num order by Id)
from Logs;
```