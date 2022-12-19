三表联查，两个基础表再加一个自己查询的临时表，临时表里通过max（）加分组查出每个部门工资最高的工资是多少就行了
```mysql
select d.Name Department,e.Name Employee,e.Salary from Department d,Employee e,
(select max(Salary) Salary,DepartmentId from Employee group by DepartmentId) z 
where e.DepartmentId=d.Id && e.DepartmentId=z.DepartmentId && e.Salary=z.Salary;