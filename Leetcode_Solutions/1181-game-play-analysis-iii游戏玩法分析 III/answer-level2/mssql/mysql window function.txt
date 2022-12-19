```
select player_id,event_date, sum(games_played) over (partition by player_id order by event_date rows between unbounded preceding and 0 following ) games_played_so_far
from activity
```

好像耗时有点长