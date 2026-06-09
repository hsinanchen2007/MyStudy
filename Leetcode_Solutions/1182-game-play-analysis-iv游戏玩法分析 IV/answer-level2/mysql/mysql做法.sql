### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select 
round(
( select count(distinct(a1.player_id)) from Activity a1
inner join Activity a2
on a1.player_id=a2.player_id and datediff(a2.event_date,a1.event_date)=1
where (a1.player_id,a1.event_date) in (select player_id,min(event_date) from Activity group by player_id)) /count(distinct(player_id)) ,2) fraction 
from Activity



```