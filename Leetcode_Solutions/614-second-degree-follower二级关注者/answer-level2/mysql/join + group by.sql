先选出distinct的follower，再通过连接和group by算数量
```
select f1.follower, count(distinct f2.follower) as num
from (select distinct follower from follow) f1 join follow f2 on f1.follower = f2.followee
group by f1.follower
```
