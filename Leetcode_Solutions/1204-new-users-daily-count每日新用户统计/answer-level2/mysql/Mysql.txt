```
select 
    minx as login_date,
    count(user_id) as user_count
from (
    select 
    user_id,min(activity_date) as minx
    from Traffic where activity='login'
    group by user_id  having  datediff('2019-06-30',minx)<=90
)s  group by minx;
```
