```
select t1.id as id,ifnull(t2.student,t1.student) as student 
from
    (select *,if(id%2=0,0,1) as a from seat) t1
left join
    (select *,if(id%2=0,0,1) as a from seat) t2
on 
    (t1.id=t2.id-1 and t1.a=t2.a+1) or 
    (t1.id=t2.id+1 and t1.a=t2.a-1)
order by t1.id asc

```
