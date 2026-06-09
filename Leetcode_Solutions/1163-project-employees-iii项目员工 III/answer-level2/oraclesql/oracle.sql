```
select
    project_id,
    employee_id
from
    (select
        p.project_id,
        e.employee_id,
        rank() over(partition by p.project_id order by e.experience_years desc) rn
    from project p, employee e
    where p.employee_id = e.employee_id)
where rn = 1
```
