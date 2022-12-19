## MySQL 联合查询
```
select
    player_id,
    device_id
from Activity
where (player_id, event_date) in (
    select 
        player_id,
        min(event_date) event_date
    from Activity
    group by player_id
)
```
## MySQL 变量
```
select
    player_id,
    device_id
from (
    select 
        player_id,
        device_id,
        case
            when @player = player_id then @num := @num + 1
            when (@player := player_id) is not null then @num := 1
        end as num
    from 
        Activity a,
        (
            select
                @player := null,
                @num := null
        ) b 
    order by a.player_id, a.event_date
) t
where num = 1
```
## MSSQL 窗口函数
速度比较慢
```
select 
    player_id,
    device_id
from (
    select 
        player_id,
        device_id,
        dense_rank() over(partition by player_id order by event_date) rnk
    from Activity
) t 
where rnk = 1
```