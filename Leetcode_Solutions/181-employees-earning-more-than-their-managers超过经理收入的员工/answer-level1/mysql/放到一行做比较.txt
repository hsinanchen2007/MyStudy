经理的id可以做关联，先把员工和经理的工资放到一行，然后作比较，这样貌似比较快。

```
select c.name as employee 
from (
    select a.name,a.salary,b.salary as M_salary 
    from employee a,employee b 
    where a.managerid=b.id)c 
where c.salary >c.M_salary;


```
