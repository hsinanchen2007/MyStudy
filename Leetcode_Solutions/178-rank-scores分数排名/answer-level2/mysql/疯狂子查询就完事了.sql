### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
Select p0.Score,Rank from Scores as p0,
(select t0.Score,count(*) as Rank from
(select distinct Score from Scores) t0,(select distinct Score from Scores) t1 
where t0.Score<=t1.Score group by t0.Score) as p1 where p0.Score=p1.Score order by Rank
```