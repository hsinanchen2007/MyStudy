使用max()获取employee中每个部门最高的工资
```
select departmentid,max(salary) as salary from employee group by departmentid;
```
关联employee，department两表，获取到其他字段
```
select c.name as department,b.name as employee,a.salary
from (select departmentid,max(salary) as salary from employee group by departmentid) a
join employee b on a.departmentid=b.departmentid and a.salary=b.salary
join department c on a.departmentid=c.id
;
```

