### 解题思路
算出所有的平均数然后作比较的一个状态值，sum状态值就可以了

### 代码

```mysql
# Write your MySQL query statement below

select
	tmp1.business_id business_id
from
	(
		select
			e1.business_id business_id,
			e1.event_type event_type,
			e1.occurences occurences,

		if (
			e1.occurences > tmp.avgocc,
			1,
			0
		) isActive
		from
			(
				select
					e.event_type event_type,
					avg(e.occurences) avgocc
				from
					Events e
				group by
					e.event_type
			) tmp
		left join Events e1 on e1.event_type = tmp.event_type
	) tmp1
group by
	tmp1.business_id
having
	sum(tmp1.isActive) >= 2
```