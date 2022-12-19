select round(count(distinct s.player_id)/ count(distinct a3.player_id),2) as fraction
from 
(select player_id
from activity a2
where exists(
    select *
    from (select a1.player_id, min(a1.event_date) as  first_log
           from activity a1
            group by a1.player_id) t
    where a2.event_date=t.first_log+1 and a2.player_id=t.player_id)) s, activity a3

