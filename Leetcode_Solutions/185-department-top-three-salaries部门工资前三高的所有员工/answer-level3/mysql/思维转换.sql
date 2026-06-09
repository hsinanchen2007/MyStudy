### 解题思路
此处撰写解题思

### 代码

```mysql
# Write your MySQL query statement below
select d1.Name as Department,e1.Name as Employee,e1.Salary
from Employee e1 join Department d1
on e1.DepartmentId=d1.Id
where (
    select count(distinct e2.Salary) from Employee e2
    where e2.Salary>e1.Salary
    and e1.DepartmentId=e2.departmentId
)<3
;
```