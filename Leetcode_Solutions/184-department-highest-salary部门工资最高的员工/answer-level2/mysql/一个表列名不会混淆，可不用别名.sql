### 解题思路
此处撰写解题思路

### 代码

```mysql
select D.Name Department,E.Name Employee, E.Salary
from Employee E join Department D
on E.DepartmentId = D.Id 
where (E.DepartmentId,E.Salary) in (
    select E.DepartmentId , max(E.Salary)
    from Employee E 
    group by E.DepartmentId
)

# Write your MySQL query statement below
select D.Name Department, E.Name Employee,E.Salary
from Employee E join Department D 
on E.DepartmentId = D.Id 
WHERE
    (E.DepartmentId , E.Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
	)
```