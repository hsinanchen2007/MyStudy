### 解题思路
这里不能使用right join 因为如果部门为空，则结果会出现['null','...','...'],如果用内连接则避免了这一问题，排除了为null结果却不为空的情况

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select d.Name Department,e.Name Employee,e.Salary Salary from Department d  join Employee e on d.Id = e.DepartmentId where (e.Salary,e.DepartmentId) in (
    select max(Salary),DepartmentId from Employee group by DepartmentId
)
```