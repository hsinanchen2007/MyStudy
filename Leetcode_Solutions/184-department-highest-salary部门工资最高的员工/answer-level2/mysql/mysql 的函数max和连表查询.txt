### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below



select c.Name as Department,a.Name  as Employee ,a.Salary   from Employee as a inner join 
(select max(Salary) as Salary,DepartmentId from Employee group by DepartmentId) as b
on a.DepartmentId =b.DepartmentId 
inner join Department as c on a.DepartmentId =c.Id 
where a. Salary =b.Salary



```