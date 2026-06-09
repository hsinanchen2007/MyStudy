```
select round(sum(case when datediff(day, a1.event_date, a2.event_date)=1 then 1.00 else 0.00 end)/count(distinct a1.player_id),2) as fraction
from 
(select player_id, event_date
from (select *, rank() over(partition by player_id order by event_date) as rankk from activity) as temp
where rankk = 1) as a1 left join activity a2 on a1.player_id = a2.player_id

```
