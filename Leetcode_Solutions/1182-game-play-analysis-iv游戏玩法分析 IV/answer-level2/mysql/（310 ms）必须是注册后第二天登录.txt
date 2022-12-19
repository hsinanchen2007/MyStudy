### 解题思路
where会自动滤除Null,可以利用这一点

### 代码

```mysql
# Write your MySQL query statement below
select ROUND(ifnull(count(distinct t1.player_id)/count(distinct t3.player_id),0),2) AS fraction
from 
    Activity t, Activity t3,
    (
    SELECT player_id,date_add(MIN(event_date),interval 1 day )AS second_date
    from Activity
    group by player_id 
    order by player_id,event_date
    ) t1
where  t.player_id =  t1.player_id and t.event_date = t1.second_date





```