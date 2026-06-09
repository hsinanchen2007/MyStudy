```mysql
select u.name, ifnull(r.travelled_distance, 0) as travelled_distance
from Users as u
left join (
    select user_id, sum(`distance`) as travelled_distance
    from Rides
    group by user_id
) r
on u.id = r.user_id
order by r.travelled_distance desc, u.name;
```