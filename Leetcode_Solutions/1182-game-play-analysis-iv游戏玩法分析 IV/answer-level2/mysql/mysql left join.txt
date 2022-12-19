```
select round(count(distinct b.player_id)/(select count(distinct player_id) from activity),2) fraction
from activity a left join (
    select player_id,min(event_date) as date2
from activity
group by player_id
) b on a.player_id = b.player_id and b.date2 <> a.event_date
where datediff(a.event_date,b.date2)=1
```

select count(distinct player_id)很神奇。
主要思想就是把diffdate=1的那个distinct id筛出来。其实我写的有点麻烦，没有必要用left join