### 解题思路
此处撰写解题思路

### 代码

```mysql

select 
        Name as Employee 
from 
        Employee e3 inner join
        (select 
                e2.Id as id1, e1.Salary as Salary1 
        from 
                Employee e1 inner join 
                Employee e2 
        on 
                e1.Id=e2.ManagerId) as A 
on 
    A.id1=e3.Id and A.Salary1<e3.Salary
```