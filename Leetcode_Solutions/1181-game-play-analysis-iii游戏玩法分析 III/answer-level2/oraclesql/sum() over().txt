```
select player_id, to_char(event_date, 'YYYY-MM-DD') event_date,
sum(games_played) over(
    partition by player_id order by event_date asc
    -- games_played rows between unbounded preceding AND current row
    ) games_played_so_far
from Activity;
```

```

```

```
