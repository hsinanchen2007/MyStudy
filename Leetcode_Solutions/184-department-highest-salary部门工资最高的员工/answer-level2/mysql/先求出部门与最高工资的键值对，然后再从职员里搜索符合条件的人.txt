### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below




select  d.Name as Department,e.Name as Employee,e.Salary
from Department d inner join Employee e
on d.Id = e.DepartmentId
where (e.Salary,e.DepartmentId) in (select max(Salary),DepartmentId from Employee group by DepartmentId)


```