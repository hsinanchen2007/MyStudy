### 解题思路
主要分两步
求出 rank 
然后 根据分数排序

### 代码

```mysql
# Write your MySQL query statement below
#排序
select a.Score,(select  count(distinct b.Score)  from Scores as b where b.Score>=a.Score) as Rank from Scores as a order by a.Score desc;
```