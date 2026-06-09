
select round((select count(1) from (select a.player_id, min(event_date) as event_date from Activity a group by a.player_id) b left join Activity c on (b.player_id = c.player_id and b.event_date + 1 = c.event_date) where c.player_id is not null) / (select count(distinct player_id) from Activity),2) as fraction from dual

