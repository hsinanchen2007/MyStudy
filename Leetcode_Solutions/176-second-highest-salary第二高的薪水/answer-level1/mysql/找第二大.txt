### 解题思路
小于最大值即为第二大

### 代码

```mysql
# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary
from Employee
where Salary < (select max(t1.Salary) from Employee as t1);
```