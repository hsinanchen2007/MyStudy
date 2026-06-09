```
# Write your MySQL query statement below
select 
    t2.ad_id,ifnull(t1.ctr,0.00) as ctr
from 
    (
    select 
        ad_id,round(100*c/(c+v),2) as ctr
    from 
        (
        select 
            ad_id,
            sum(if(action='Clicked',1,0)) as c,
            sum(if(action='Viewed',1,0)) as v
        from 
            Ads
        where 
            action<>'Ignored'
        group by 
            ad_id
        ) as tmp
    ) t1 
right join 
(
select 
    distinct ad_id 
from 
    Ads
) t2
on 
    t1.ad_id=t2.ad_id
order by 
    ctr desc,t2.ad_id
```
