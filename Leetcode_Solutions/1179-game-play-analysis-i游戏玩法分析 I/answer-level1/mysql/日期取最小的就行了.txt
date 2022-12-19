### 解题思路

简单的分组和最小
### 代码

```mysql
# Write your MySQL query statement below
select player_id, min(event_date) `first_login` from Activity group by player_id order by player_id asc
```