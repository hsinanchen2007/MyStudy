# Write your MySQL query statement below
#菜鸡硬刚,我就是这样刚出来的
/*
select employee_id 
from Employees
where manager_id=1
and employee_id<>1
union 
select employee_id
from Employees
where manager_id in (select employee_id 
from Employees
where manager_id=1
and employee_id<>1)
union
select employee_id
from Employees
where employee_id in
(select employee_id
from Employees
where manager_id in (select employee_id 
from Employees
where manager_id=1
and employee_id<>1))
union
select employee_id
from Employees
where manager_id in(
select employee_id
from Employees
where employee_id in
(select employee_id
from Employees
where manager_id in (select employee_id 
from Employees
where manager_id=1
and employee_id<>1)))
*/
#方法2
#多表左链接，参考评论 开心果 id做法
#最终都会收敛到ceo
select e1.employee_id
from Employees e1 
left join Employees e2 on e1.manager_id = e2.employee_id
left join Employees e3 on e2.manager_id = e3.employee_id
where e3.manager_id=1 and e1.employee_id<>1;