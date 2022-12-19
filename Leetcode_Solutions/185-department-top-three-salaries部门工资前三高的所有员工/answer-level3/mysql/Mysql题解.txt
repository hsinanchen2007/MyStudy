select B.Name as Department,A.Name as Employee,A.Salary as Salary
from Employee A,Department B
where A.DepartmentId=B.Id and
3>(select count(distinct C.Salary) from Employee C where C.DepartmentId=B.Id and C.Salary>A.Salary)