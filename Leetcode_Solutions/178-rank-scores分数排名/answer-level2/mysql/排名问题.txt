### 解题思路
lc版本的mysql不能用窗口函数

排名也即不小于本条记录的score的记录数目

### 代码

```mysql
# Write your MySQL query statement below
select s1.Score, 
(
    select count(distinct(s2.Score))
    from Scores as s2
    where s2.Score >= s1.Score
) as Rank
from Scores as s1
order by s1.Score desc;
```