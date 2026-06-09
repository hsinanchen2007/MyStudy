### 解题思路
子查询先查询排列序号及对应分数，然后左连接分数表，条件分数相同时，降序输出
### 代码

```mysql
# Write your MySQL query statement below


select s.Score,Rank
from
(
    select (@i:=@i+1) as Rank,t.Score from (select @i:=0) as it,
    (select Score from Scores group by Score order by Score desc) t
) r
left join Scores s
on s.Score = r.Score
order by s.Score desc;
```