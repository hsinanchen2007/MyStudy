```
# 使用子查询
select 
    c.name as Department ,a.name  as employee ,a.salary as salary
from  
    employee a ,
    (select max(salary)as salary ,departmentid from employee group by departmentid)b,
    Department c
where 
    a.salary = b.salary 
    and a.departmentid = b.departmentid 
    and a.departmentid=c.Id;
```
    
# 使用exists
```
select 
    d.name as department,
    c.name as Employee ,
    c.salary as salary
from 
    (SELECT 
        a.* FROM Employee a 
     WHERE
        NOT EXISTS (
            SELECT 1 FROM Employee b 
            WHERE  a.DepartmentId = b.DepartmentId AND a.salary<b.salary)
    )c,
    department d
where 
    c.departmentid = d.id;
 ```   
    
# 使用in

```
select 
    d.name as department,
    c.name as Employee ,
    c.salary as salary
from 
    (SELECT 
        * FROM Employee
     WHERE (DepartmentId,salary) 
       not in(
            SELECT a.DepartmentId,a.salary FROM Employee a ,Employee b 
            WHERE  a.DepartmentId = b.DepartmentId AND a.salary<b.salary)
    )c,
    department d
where 
    c.departmentid = d.id;
```