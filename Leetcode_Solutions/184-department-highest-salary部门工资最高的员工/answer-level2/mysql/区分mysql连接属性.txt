### 解题思路
用了left join,总是与目标数据有一些差距

### 代码

```mysql
# Write your MySQL query statement below
select 
    d.`name` as Department,
    e.`name` as Employee, 
    e.Salary 
from Employee e 
join Department d on e.departmentId = d.id 
where 
    (e.departmentId,e.salary) in (select DepartmentId,max(salary) from Employee group by departmentId)

```