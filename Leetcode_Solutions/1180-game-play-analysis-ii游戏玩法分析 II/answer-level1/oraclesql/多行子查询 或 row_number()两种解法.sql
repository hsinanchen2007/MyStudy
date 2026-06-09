```
-- 使用多行子查询
select player_id, device_id
from Activity
where (player_id, event_date) -- 注意要限制(player_id, event_date)两者都在子查询的集合里
in(
    select player_id, min(event_date) from Activity group by player_id
)
order by player_id asc;

-- 使用row_number
select player_id, device_id
from (
    select player_id, device_id,
    row_number() over(partition by player_id order by event_date asc) rn,
    games_played
    from Activity
)
where rn = 1
order by player_id asc;

```
