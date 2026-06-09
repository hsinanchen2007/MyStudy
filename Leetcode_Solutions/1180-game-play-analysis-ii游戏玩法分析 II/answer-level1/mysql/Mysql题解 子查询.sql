select player_id,device_id 
from Activity A1
where event_date=(select min(event_date) from Activity A2 where A1.player_id=A2.player_id)