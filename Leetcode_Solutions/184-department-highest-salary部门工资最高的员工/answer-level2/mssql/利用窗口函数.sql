### 解题思路
利用Window function

### 代码

```mssql
/* Write your T-SQL query statement below */

with t as (
    select d.Name as Department, e.Name as Employee, Salary,
    rank() over (partition by d.Name order by Salary DESC) as num
    from Employee as e
    inner join Department as d
    on DepartmentId = d.Id
)
select Department, Employee, Salary
from t
where num = 1;
