```mysql
select 
    ROUND(
        tmp.acc / (select count(distinct(player_id)) as totalCount from Activity),
        2
    ) as fraction
from (
    select
        if (
            @preId = a.player_id,
            # id相等
            if (
                @skip,
                -1,
                # id相等，未统计
                if (
                    date_add(@preDate, interval 1 day) = a.event_date, 
                    # id相等，未统计，日期连续
                    if (@skip := true, @count := @count + 1, -1),
                    if (@skip := true, -1, -1)
                )
            ),
            # id不等
            if (
                @preId := a.player_id,
                if (
                    @preDate := a.event_date,
                    @skip := false,
                    -1
                ),
                -1
            )
        ) as acc
    from 
        Activity a,
        (select @preId := null, @preDate := null, @count := 0, @skip := false) ignored
    order by a.player_id, a.event_date asc
) tmp
order by tmp.acc desc
limit 1
```
