```
# Write your MySQL query statement below
select activity
from Friends
group by activity
having count(*) <> 
(select max(cnt)
from 
    (select activity,count(*) as cnt
    from Friends
    group by activity
    ) tmp
)
and count(*) <>
(select min(cnt)
from 
    (select activity,count(*) as cnt
    from Friends
    group by activity
    ) tmp
)
```
