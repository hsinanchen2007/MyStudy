## MySQL 的 min 函数
```
select round((
    select
        count(a1.player_id) cnt 
    from 
        Activity a1,
        (
            select 
                player_id,
                min(event_date) event_date
            from Activity
            group by player_id
        ) a2
    where 
        a1.player_id = a2.player_id and
        datediff(a1.event_date, a2.event_date) = 1 
) / count(distinct a.player_id), 2) fraction
from Activity a
```
## MSSQL 的窗口函数
```
select
    round(sum(
        case
            when datediff(day, a2.event_date, a1.event_date) = 1 then 1.00
            else 0.00
        end
    ) / count(distinct a1.player_id), 2) as fraction
from 
    Activity a1,
    (
        select * 
        from (
            select 
                player_id,
                event_date,
                rank() over(partition by player_id order by event_date) rnk
            from Activity
        ) t 
        where t.rnk = 1
    ) a2
where 
    a1.player_id = a2.player_id
```
