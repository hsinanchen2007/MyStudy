select a.player_id, a.event_date, 
(select sum(d.games_played) from activity d where a.player_id=d.player_id 
and d.event_date<= a.event_date) as games_played_so_far 
from activity a 
order by a.player_id, a.event_date