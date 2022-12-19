### 解题思路
先子查询找出每个部门对应的id，name和最高工资。然后inner join员工表,最后条件输出工资等于最大工资的员工

### 代码

```mysql


select t.Name as Department,m.Name as Employee ,maxSalary as Salary
from
Employee m inner join
(
select e.DepartmentId,d.Name,max(e.Salary) as maxSalary 
from Employee e right join Department d 
on e.DepartmentId = d.ID 
group by d.Id
) t
on m.DepartmentId = t.DepartmentId 
where t.maxSalary = m.Salary
```