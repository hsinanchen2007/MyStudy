主要从获取第一高，第二高，第三高三步来获取对应的薪水值。
SQL比较长：
执行493ms

```
select d.name as Department ,e.name as Employee ,e.Salary
from Employee e,
Department d,

(
    select (
        case
            when t3.max_3 is null then (
                case 
                    when t2.max_2 is null then t1.max_1
                    else t2.max_2
                end 
            ) 
            else t3.max_3
        end 
    ) maxS,d.id
    from
    Department d 
    left join
    
    (
            select max(Salary) max_1,DepartmentId 
            from Employee 
            group by DepartmentId
    ) t1 on d.id = t1.DepartmentId

    left join 
    (
        select max(e1.Salary) max_2, e1.DepartmentId
        from Employee e1,
        (
            select max(Salary) max_1,DepartmentId 
            from Employee 
            group by DepartmentId
        ) t1
        where e1.DepartmentId = t1.DepartmentId
        and e1.Salary < t1.max_1
        group by e1.DepartmentId
    ) t2 on d.id = t2.DepartmentId

    left join 
    (
        select max(e2.Salary) max_3,e2.DepartmentId 
        from Employee e2,
        (
            select max(e1.Salary) max_2, e1.DepartmentId
            from Employee e1,
            (
                select max(Salary) max_1,DepartmentId 
                from Employee 
                group by DepartmentId
            ) t1
            where e1.DepartmentId = t1.DepartmentId
            and e1.Salary < t1.max_1
            group by e1.DepartmentId
        ) t2 
        where e2.DepartmentId = t2.DepartmentId
        and e2.Salary < t2.max_2
        group by e2.DepartmentId
    ) t3 on d.id = t3.DepartmentId
) t
where e.DepartmentId = d.id 
and d.id = t.id
and e.Salary >= t.maxS
order by e.DepartmentId,e.Salary desc
```
