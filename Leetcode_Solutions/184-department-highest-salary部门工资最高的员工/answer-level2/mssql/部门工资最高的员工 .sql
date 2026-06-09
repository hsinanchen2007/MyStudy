1. 先用rank和开窗函数进行组内工资降序排序
2. 然后选出rank=1的员工
select
    t1.D Department ,
    t1.E Employee ,
    t1.S Salary 
from
    (select
        d.Name D,
        e.Name E,
        e.Salary S,
        rank() over(partition by d.Name order by e.Salary desc) R
    from Employee e
    join Department d
    on e.DepartmentId = d.Id)t1
where t1.R=1