
select c.Department,c.Employee,c.Salary
from
(select 
    b.Name as Department, 
    a.Name as Employee,
    a.Salary,
    dense_rank() over (partition by a.DepartmentId order by a.Salary desc) as rank_
from Employee a
inner join Department b
on a.DepartmentId=b.Id)c

where c.rank_<=3




能用函数为啥不用函数，多方便。。。。。