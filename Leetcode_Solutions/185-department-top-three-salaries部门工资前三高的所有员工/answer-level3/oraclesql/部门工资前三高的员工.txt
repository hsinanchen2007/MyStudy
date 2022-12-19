/* Write your PL/SQL query statement below */
select d.name  Department, temp.Name Employee, temp.Salary
from(
    select Name, DepartmentId, Salary,
        dense_rank() over (partition by DepartmentId order by Salary desc) rank
    from Employee
    ) temp, Department d
where temp.DepartmentId=d.Id and temp.rank <= 3;