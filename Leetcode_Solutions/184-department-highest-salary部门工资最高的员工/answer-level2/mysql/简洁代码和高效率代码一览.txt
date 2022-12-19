简洁的代码，全表扫描，效率低：
```
select d.Name Department, e1.Name Employee, e1.salary Salary from Employee e1, Department d where d.Id = e1.DepartmentId
and e1.salary = (select max(e2.salary) from Employee e2 where e2.DepartmentId=e1.DepartmentId);
```

先进行结果数据集的筛选，再利用外键索引连接提高检索效率；
最大化最左匹配原则，需将salary最后匹配；
```
select d.Name Department, e2.Name Employee, t1.ms Salary from 
(select e1.DepartmentId, max(e1.Salary) ms from Employee e1 group by DepartmentId) t1, Department d, Employee e2 where d.Id=t1.DepartmentId and t1.DepartmentId=e2.DepartmentId and  t1.ms=e2.Salary;
```
