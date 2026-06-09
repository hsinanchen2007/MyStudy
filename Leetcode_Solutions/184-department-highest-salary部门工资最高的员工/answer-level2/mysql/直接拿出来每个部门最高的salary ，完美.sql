### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select 
   t3.Name  Department ,
   t1.Name  Employee ,
   t1.Salary Salary 
from 
    Employee t1 
left join 
    (select DepartmentId,max(Salary) Salary from Employee  group by DepartmentId) t2 on t1.DepartmentId=t2.DepartmentId 
left join
    Department t3 on t3.Id =t1.DepartmentId 
where t1.Salary =t2.Salary and t3.Name is not null

```