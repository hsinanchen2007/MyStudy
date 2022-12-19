### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select e1.employee_id 
from Employees e1
where e1.employee_id!=1 and e1.manager_id = 1 
union 
select e2.employee_id
from Employees e1, Employees e2 
where e1.employee_id!=1 and e1.manager_id=1 and e2.employee_id!=1 and  e2.manager_id = e1.employee_id
union 
select e3.employee_id 
from Employees e1, Employees e2, Employees e3 
where e1.employee_id!=1 and e1.manager_id=1 and e2.manager_id=e1.employee_id and e3.employee_id!=1 and e3.manager_id = e2.employee_id

```