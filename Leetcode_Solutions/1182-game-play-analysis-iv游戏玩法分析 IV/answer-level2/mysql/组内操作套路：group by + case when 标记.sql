# Write your MySQL query statement below
#组内操作套路：group by + case when 标记
select round(sum(tag)/count(player_id),2) fraction
from
(select player_id,case when date_add(min(event_date),interval 1 day) in (select event_date from Activity a2 where a2.player_id=a1.player_id) then 1 else 0 end tag
from Activity a1
group by player_id)t1