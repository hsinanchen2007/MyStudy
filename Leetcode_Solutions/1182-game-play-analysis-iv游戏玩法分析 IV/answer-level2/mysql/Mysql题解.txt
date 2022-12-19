select 
Round(count(distinct A1.player_id)/(select count(distinct player_id) from Activity),2)fraction
from Activity A1,Activity A2
where datediff(A1.event_date,A2.event_date)=1
and A1.player_id=A2.player_id 
and A2.event_date=(select min(event_date) from Activity where player_id=A1.player_id)