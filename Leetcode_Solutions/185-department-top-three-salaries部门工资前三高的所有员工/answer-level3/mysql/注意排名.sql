### 解题思路
第一步：自定义变量对每个部门的员工工资进行排名，注意去重
第二步：筛选出排名≤3的工资
第三步：使用where型子查询

### 代码

```mysql
select
    d.Name Department,
    e.Name Employee,
    e.Salary
from Employee e,Department d
where e.DepartmentId=d.Id
and (e.DepartmentId,e.Salary)
in
(
    select e2.DepartmentId,e2.Salary
    from 
    (
        select e1.DepartmentId,e1.Salary,@a:=if(@pre=DepartmentId,@a+1,1)Rnk,@pre:=DepartmentId
        from (select distinct DepartmentId,Salary from Employee order by DepartmentId, Salary desc)e1,(select @a:=1,@pre:=null)p
    )e2
    where Rnk<=3
)
order by e.DepartmentId,e.Salary desc,e.Name;


  
```