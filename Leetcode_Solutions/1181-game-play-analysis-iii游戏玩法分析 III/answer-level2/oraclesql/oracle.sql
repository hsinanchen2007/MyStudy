```
select
    player_id,
    to_char(event_date, 'yyyy-mm-dd') as event_date,
    sum(games_played) over(partition by player_id order by event_date) games_played_so_far
from activity
```
