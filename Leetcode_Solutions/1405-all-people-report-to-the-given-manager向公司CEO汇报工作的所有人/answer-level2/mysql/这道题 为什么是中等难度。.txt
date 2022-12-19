```
select a.employee_id as EMPLOYEE_ID
from 
    Employees as a 
    left join 
    Employees as b on a.manager_id = b.employee_id
    left join
    Employees as c on b.manager_id = c.employee_id
    left join
    Employees as d on c.manager_id = d.employee_id
where 
    a.employee_id <> 1 
    and
    d.employee_id = 1; 
```
