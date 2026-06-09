### 解题思路
此处撰写解题思路
筛选条件的时候必须也筛选 departmentid in新的表中 ，为什么呢？
因为一个部门的第二高工资可能等于另一个部门的第一高工资

### 代码

```mysql
# Write your MySQL query statement belowselect
select d.name Department ,e.name Employee , e.salary salary  from Employee e join Department d on e.DepartmentId=d.id 
 where (e.Salary,e.DepartmentId) in (select max(Salary),DepartmentId from Employee group by DepartmentId);
```