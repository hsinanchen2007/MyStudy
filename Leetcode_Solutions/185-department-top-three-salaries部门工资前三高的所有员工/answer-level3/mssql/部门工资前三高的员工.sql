1. 使用dense_rank()方法对组内员工工资降序排序
2. 然后取出rank<=3的所有员工

select
    t1.D Department,
    t1.E Employee,
    t1.S Salary
from
    (select
        d.Name D,
        e.Name E,
        e.Salary S,
        dense_rank() over(partition by d.Name order by e.Salary desc) R
    from Employee e
    join Department d
    on e.DepartmentId = d.Id)t1
where t1.R <= 3