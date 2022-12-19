### 解题思路
此处撰写解题思路
不是最大数的最大数就是第二大数
### 代码

```oraclesql
select 
max(Salary) SecondHighestSalary
from Employee
where
salary<(select max(Salary) from Employee)

```