
```sql
select
	id, company, salary
from
	(select
		id, company, salary,
		row_number() over (partition by company order by salary) as rn, -- 各薪水记录在其公司内的顺序编号
		count(1) over (partition by company) as cnt -- 各公司的薪水记录数
	from employee
	)
where abs(rn - (cnt+1)/2) < 1 -- 顺序编号在公司薪水记录数中间的，即为中位数
```
