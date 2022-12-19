```mysql
select
    a.player_id as player_id,
    a.event_date as event_date,
    case
        when @preId = a.player_id then @count := @count + a.games_played
        when @preId := a.player_id then @count := a.games_played
    end as games_played_so_far
from Activity a, ( select @preId := null, @count := 0 ) ignored
order by a.player_id, a.event_date asc
```
