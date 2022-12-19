```
select
    s1.id ,
    case
    when s1.id % 2 = 1 and s2.student is not null then s2.student
    when s1.id % 2 = 1 and s2.student is null then s1.student
    when s1.id % 2 = 0 then s3.student
    end as student
from seat s1
left join seat s2 on (s2.id - 1= s1.id)
left join seat s3 on (s3.id + 1= s1.id)
order by s1.id
```