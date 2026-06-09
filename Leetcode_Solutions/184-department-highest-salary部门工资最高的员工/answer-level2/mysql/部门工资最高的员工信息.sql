### 解题思路
解这道题的关键点在where条件中
先将两张表关联起来，然后在where条件中过滤掉不满足条件的数据。

### 代码

```mysql
select b.Name as Department,a.Name as Employee,a.Salary as Salary from Employee a 
inner join Department b on a.DepartmentId=b.Id
where (a.DepartmentId,a.Salary) in (select DepartmentId,Max(Salary) as MaxSalary
from Employee
group by DepartmentId)
 
```