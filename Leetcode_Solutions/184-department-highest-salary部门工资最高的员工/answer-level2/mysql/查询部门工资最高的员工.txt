### 解题思路
有一个易错点：如果在查询外部使用group by的话，就会出现有多个最高工资的人，但是只查出来一个的情况，所以group by要在子查询中使用。
使用in时，可以是多个列包含，不局限于单个列。

### 代码

```mysql
# Write your MySQL query statement below

select dept.Name Department, emp.Name Employee, emp.Salary Salary
from Employee emp
 join Department dept on emp.DepartmentId = dept.Id
where (DepartmentId, Salary) in (
    select DepartmentId, max(Salary) Salary
    from Employee
    group by DepartmentId
)
```