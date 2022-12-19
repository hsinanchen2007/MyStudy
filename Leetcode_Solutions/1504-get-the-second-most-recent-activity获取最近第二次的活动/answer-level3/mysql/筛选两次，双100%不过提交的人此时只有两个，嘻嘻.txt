先剔除掉活动开始时间最近的且这个人活动数超过1的
然后再选出活动开始时间第二近的
```
select u.*
from UserActivity u
where (u.username, u.startDate) in 
(
    select a.username, max(a.startDate) 
    from UserActivity a 
    where (a.username, a.startDate) not in (
        select b.username, max(b.startDate)
        from UserActivity b
        group by b.username
        having count(b.username) > 1
    ) 
    group by a.username
) 
```

