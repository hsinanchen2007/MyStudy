### 解题思路
1.在员工表查询出每个部门最高的工资
# select max(Salary) Salary,DepartmentId from Employee group by DepartmentId
2.关联查询,把员工表,部门表和子查询关联,取各个表中需要的字段

### 代码

```mysql
# Write your MySQL query statement below
select d.Name Department,e.Name Employee,t1.Salary from Employee e join Department d on d.Id = e.DepartmentId join
(select max(Salary) Salary,DepartmentId  from Employee group by DepartmentId) t1 on t1.Salary = e.Salary and t1.DepartmentId = e.DepartmentId;
```