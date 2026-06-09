```
select 
    t1.Email
from
    (select 
        Email,
        count(Email) as num
    from
        Person
    group by
        Email
    having
        num > 1
    ) t1
;
```
