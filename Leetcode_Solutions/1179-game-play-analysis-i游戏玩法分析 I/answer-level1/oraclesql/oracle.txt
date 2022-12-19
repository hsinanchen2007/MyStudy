```
select
	player_id,
	to_char(event_date, 'yyyy-mm-dd') as first_login
from
	(select
		player_id,
		event_date,
		row_number() over (partition by player_id order by event_date asc) rn
	from Activity)
where rn = 1
```
