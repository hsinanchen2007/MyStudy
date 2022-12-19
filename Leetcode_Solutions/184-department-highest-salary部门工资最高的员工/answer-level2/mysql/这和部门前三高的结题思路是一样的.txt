### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select d.Name as Department,  e.Name as Employee ,  e.Salary from Employee as e join Department as d on e.DepartmentId = d.Id 
where e.id in (select e1.Id
from Employee as e1 
join Employee as e2
on e1.Salary <= e2.salary and e1.DepartmentId = e2.DepartmentId
group by e1.Id,e1.DepartmentId
having count(distinct e2.Salary) = 1)

```