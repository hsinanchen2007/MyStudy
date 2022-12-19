### 解题思路
简单关联

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select  c.department ,c.Employee,c.salary
from (select a.Name as Employee ,b.Name as department ,a.salary,b.id from Employee a,Department b 
where a.DepartmentId = b.id) c,(select t.DepartmentId ,max(t.salary) as salary from Employee t group by t.DepartmentId )d
where c.salary=d.salary and c.id = d. DepartmentId ;
```