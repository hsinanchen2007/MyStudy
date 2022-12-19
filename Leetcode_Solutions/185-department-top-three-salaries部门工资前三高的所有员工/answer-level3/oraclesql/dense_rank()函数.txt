### 解题思路
此题不能使用常规的row_number()函数，因为可能存在两个工资并列的情况
所以要用dense_rank()要解题

### 代码

```oraclesql
/* Write your PL/SQL query statement below */

select n.Department, n.Employee, n.Salary  from 
(
select 
m.*,
dense_rank() over(partition by m.Department order by m.Salary desc ) as rm
from
    (select 
    d.Name as Department,
    e.Name as Employee,
    e.Salary as Salary
    from Employee e
    inner join Department d
    on e.DepartmentId = d.Id 
    ) m
) n 
where n.rm < 4


```