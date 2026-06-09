```
select project_id
from
    (select
        project_id,
        rank() over (order by count(1) desc) rn
    from project
    group by project_id)
where rn = 1
```
