### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select S1.gender, S1.day, sum(S2.score_points) as total
from
Scores as S1
left join
Scores as S2
on S1.gender = S2.gender and S1.day >= S2.day
group by S1.day,S1.gender
order by S1.gender, S1.day, S2.day
```