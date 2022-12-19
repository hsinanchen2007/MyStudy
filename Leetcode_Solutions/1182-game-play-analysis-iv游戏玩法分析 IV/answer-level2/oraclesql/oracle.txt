

```sql
select
    cast
    (
        (select count(player_id) -- 首次登录后，次日又有登录的用户
    	from
            (select
                    player_id, event_date,
                    min(event_date) over (partition by player_id) first_login_date
                from activity
             )
         where event_date = first_login_date + 1
        )
        
        /
        
        (select count(distinct player_id) from activity) -- 总用户数
        
        as number(10, 2)
     ) as fraction
from dual
```
