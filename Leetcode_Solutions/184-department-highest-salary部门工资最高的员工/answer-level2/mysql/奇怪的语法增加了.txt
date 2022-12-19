### 解题思路
此处撰写解题思路

### 代码

```mysql

select
     d.Name as Department,
     e.Name as Employee,
     Salary as Salary

from 
    Employee e  join Department d
on
    e.DepartmentId=d.Id

where
    ( e.DepartmentId,Salary)
in
(select 
    DepartmentId, max(Salary) 
from
    Employee 
 group by 
    DepartmentId
);
```