# Write your MySQL query statement below
#方法1
#自连接+分组查询
/*
select e1.employee_id,count(e2.employee_id) team_size
from Employee e1,Employee e2
where e1.team_id=e2.team_id
group by e1.employee_id
*/

#方法2：分组+组内子查询
select e1.employee_id,(select count(*) from Employee e2 where e2.team_id=e1.team_id) team_size
from Employee e1
group by e1.employee_id