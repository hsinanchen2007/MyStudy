```
select
    f1.follower as follower, count(distinct f2.follower) as num
from follow f1, follow f2
where f1.follower = f2.followee
group by f1.follower
order by f1.follower
```
