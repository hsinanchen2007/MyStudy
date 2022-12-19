### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select

a.score as Score,

count(DISTINCT b.score) AS Rank # 统计b表符合条件的不重复的分数的数量作为排名

FROM scores a join scores b

where b.score >= a.score # 条件是这个分数不小于我，因为a、b表数据相同，所以排名值最小是1

group by a.id # a表中每个数据都进行排名

order by a.score DESC # 最后按分数（跟排名一样）降序排列
```