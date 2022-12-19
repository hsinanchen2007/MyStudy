### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select e1.Name as 'Employee', e1.Salary,D.Name Department 
from Employee e1 join Department as D on e1.DepartmentId  = D.Id
where 3 >
(
    select count( distinct e2.Salary)
    from Employee e2
    where e2.Salary > e1.Salary and e2.DepartmentId=e1.DepartmentId
)
order by  Department,e1.Salary desc
;
```