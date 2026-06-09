### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select 
    t.player_id,
    min(t.event_date) as first_login 
from Activity t   
group by t.player_id
```