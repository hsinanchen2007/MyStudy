select b.player_id as player_id, b.device_id as device_id from 
   (select a.*, dense_rank() over (partition by a.player_id order by a.event_date asc) as rk from Activity a) b
where rk < 2