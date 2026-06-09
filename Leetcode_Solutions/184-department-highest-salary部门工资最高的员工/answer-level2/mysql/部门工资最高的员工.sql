对mysql不熟悉，按照HiveSql的习惯来写的

```
select 
    t3.name as Department,
    t1.Name as Employee,
    t1.Salary
from
    (select 
        DepartmentId,
        Name,
        Salary
    from
        Employee
    ) t1
left join
    (select
        max(Salary) as Salary,
        DepartmentId
    from
        Employee
    group by
        DepartmentId
    ) t2
    
on
    t1.Salary=t2.Salary and t1.DepartmentId=t2.DepartmentId

left join    
    (select
        Id,
        Name
    from 
        Department
    ) t3
on
    t1.DepartmentId=t3.Id

where
    t2.Salary is not null and t3.Name is not null
;
```

