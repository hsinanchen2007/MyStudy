### 解题思路
此处撰写解题思路

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select Score,
dense_rank() over(order by score desc) as Rank
from Scores
order by Score desc;
```