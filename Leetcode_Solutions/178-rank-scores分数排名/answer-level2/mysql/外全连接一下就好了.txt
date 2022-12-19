### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select  a.Score,count(*) as Rank
from Scores as a
left join (
    select distinct Score from Scores
) as b
on true
where b.Score>=a.Score
group by Id
order by a.Score desc
```