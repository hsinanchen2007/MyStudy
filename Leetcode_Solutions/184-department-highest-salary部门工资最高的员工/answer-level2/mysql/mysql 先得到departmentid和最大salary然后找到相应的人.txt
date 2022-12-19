```mysql
# Write your MySQL query statement below

SELECT Department.Name AS 'Department', Employee.Name AS 'Employee', Salary from Employee join Department ON Employee.DepartmentId = Department.Id  where (Employee.DepartmentId, Employee.Salary) in
(SELECT DepartmentId, Max(Salary) from Employee group by DepartmentId);
```