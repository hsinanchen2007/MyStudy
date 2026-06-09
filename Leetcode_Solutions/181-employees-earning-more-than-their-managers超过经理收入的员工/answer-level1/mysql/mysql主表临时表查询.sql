### 解题思路
主表
员工临时表
经理临时表

### 代码

```mysql
# Write your MySQL query statement below

select a.Name as Employee 
from Employee as a 
inner join Employee as b on a.Id =b.Id 
inner join Employee as c on b.ManagerId = c.Id  
where b.ManagerId >0 and  c.Salary <b.Salary

```