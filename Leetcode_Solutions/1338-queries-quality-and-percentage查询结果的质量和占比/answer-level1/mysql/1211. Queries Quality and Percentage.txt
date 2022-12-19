### 解题思路
合理利用 case when。代码写多了自然就有感觉了

### 代码

```mysql
# Write your MySQL query statement below

select query_name,
round((sum(rating/position)/count(query_name)),2) as quality,
round((sum(case when rating < 3 then 1 else 0 end) * 100 /count(query_name)),2) as poor_query_percentage
from queries 
group by query_name
```