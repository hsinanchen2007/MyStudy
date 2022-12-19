将表拷贝一份，用于查询对应经理并比较收入

代码：
```
select e1.name as employee
from employee as e1, employee as e2
where e1.managerid = e2.id and e1.salary > e2.salary
```
