### 解题思路
先通过group by分组max最大的salary，然后通过连接D表找到对应的部门名称，再通过连接E表找到对应的员工，最后返回结果。通过中间表。

### 代码

```mysql
# Write your MySQL query statement below
select 
t.Name as Department,
e.Name as Employee, 
e.Salary as Salary
from(
    select DepartmentId, 
        d.name as Name ,
        max(Salary) as Salary from Employee  e
    join Department d on d.Id = e.DepartmentId 
    group by DepartmentId) as t
join Employee e
on t.DepartmentId = e.DepartmentId and e.Salary = t.Salary
```

