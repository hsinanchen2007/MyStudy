### 解题思路 祝大家早日加入部门工资最高的员工行列
此处撰写解题思路

### 代码

```mysql
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