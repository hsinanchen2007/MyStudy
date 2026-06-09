### 解题思路
先把部门和工资去重，然后与员工表交叉连接，只取工资比该员工高的，最后按员工ID分组，总数不超过3的即为所求，按部门和工资排序就可以了。

### 代码

```mysql
# Write your MySQL query statement below
select d.Department as Department, c.Name as Employee, c.Salary as Salary
from Employee c
join(
    select distinct a.Salary as Salary, b.Id as DepartmentId, b.Name as Department
    from Employee a
    join Department b
    on a.DepartmentId = b.Id
) d
on c.DepartmentId = d.DepartmentId and c.Salary <= d.Salary
group by c.Id
having count(*)<=3
order by c.DepartmentId, c.Salary desc
```