```
/* Write your PL/SQL query statement below */
select Department,Employee,Salary 
from(
select d.Name Department,e.Name Employee,e.Salary Salary ,
dense_rank()over(partition by e.DepartmentId order by e.Salary desc) rn
from Employee e,Department d
where e.DepartmentId=d.Id 
)
where rn<=3;
```