```
select
	player_id, device_id
from
	(select
		player_id,
		device_id,
		row_number() over(partition by player_id order by event_date asc) rn
	from Activity)
where rn = 1
```
