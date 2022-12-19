### 解题思路
题目说不超过三个中间经理。还行吧那就三个嵌套的subquery

### 代码

```mysql
# Write your MySQL query statement below


select employee_id
from employees
where (manager_id in 
(
select employee_id 
from employees
where manager_id in (
select employee_id
from employees
where manager_id = 1
)))
and employee_id<>1










```