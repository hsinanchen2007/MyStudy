### 解题思路
表做小于等于自连接，按id分组 ， 用count(distinct score)计算大于等于自身值的个数，那就是排名。
### 代码

```mysql
# Write your MySQL query statement below
 select a.score   ,count(distinct b.score) as Rank from scores a join scores b on a.score  <= b.score group by a.id  order by a.score desc   ;
```