SELECT d.Name Department,e1.Name Employee,e1.Salary Salary
From Employee e1 left join Department d on d.Id=e1.DepartmentId
Where e1.Salary=
(SELECT max(Salary) 
FROM Employee e2
Where e1.DepartmentId=e2.DepartmentId
Group by DepartmentId )


运行代码的结果一致，但是因为顺序跟官方设定不一致，所以提交失败，不知道效率几何