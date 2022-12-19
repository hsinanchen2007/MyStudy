### 解题思路
此处撰写解题思路
将去重后的表进行自关联，找出辅表中大于等于主表中当前元素的个数作为排名
### 代码

```mysql
# Write your MySQL query statement below
select 
c.Score,
d.Rank
from Scores c
inner join 
	(
		select 
		a.Score,
		count b.Score as Rank
		from 
		#将score表去重后自关联，找出大于等于当前元素的去重后的元素的个数作为rank排名
		(select distinct Score from Scores) a inner join 
		(select distinct Score from Scores) b on a.Score <= b.Score group by a.Score
	) d on c.Score = d.Score
order by c.Score desc
;
```