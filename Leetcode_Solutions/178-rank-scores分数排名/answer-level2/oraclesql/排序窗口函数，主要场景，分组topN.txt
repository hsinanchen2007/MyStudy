### 解题思路
    row_number() 是没有重复值的排序
    dense_rank() 是连续排序，两个第二名仍然跟着第三名
    rank()       是跳跃拍学，两个第二名下来就是第四名

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select
Score,dense_rank() over(order by Score desc) as Rank
from Scores
```