### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select install_dt, count(*) as installs, round(sum(is_retention)/count(*), 2) as Day1_retention
from 
(select install_a.install_dt, install_a.player_id, if(a.event_date is null, 0, 1) as is_retention
from 
(select player_id, min(event_date) as install_dt 
from Activity 
group by player_id
) as install_a
left join Activity as a 
on install_a.player_id = a.player_id and a.event_date = date_add(install_a.install_dt, interval 1 day)
) as t
group by install_dt
```