### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select Department,Employee,Salary
from
(select 
    (select Name  from Department where Id=t1.DepartmentId) Department  ,
    t1.Name Employee ,
    t1.Salary,
    (select count(distinct t2.Salary)+1 from Employee t2 where t2.Salary>t1.Salary and t2.DepartmentId =t1.DepartmentId ) rank
from
Employee t1) t3
where t3.rank<=3 and Department is not null
order by Department,Employee
```