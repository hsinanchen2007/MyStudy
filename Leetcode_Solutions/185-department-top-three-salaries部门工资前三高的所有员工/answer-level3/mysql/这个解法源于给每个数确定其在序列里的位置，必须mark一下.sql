### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
#select d.Name as Department ,e1.Name as Employee ,e1.Salary from
#Employee as e1
#join Department as d on d.id = e1.DepartmentId 
#where  (select count(distinct e2.Salary) from Employee as e2
#where e1.salary <= e2.salary and e1.DepartmentId = e2.DepartmentId) <= 3
select d.Name as Department , e.Name as Employee , e.Salary from Employee as e
join Department d on d.id = e.DepartmentId 
where e.id in
(select e1.id from Employee as e1
join Employee as e2
on e1.Salary <= e2.Salary and e1.DepartmentId = e2.DepartmentId
group by e1.id,e1.DepartmentId
having count(distinct e2.Salary) <=3 )

```