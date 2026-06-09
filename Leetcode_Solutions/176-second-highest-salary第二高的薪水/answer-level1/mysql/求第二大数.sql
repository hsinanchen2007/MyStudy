### 解题思路
求第二高的薪水，就是除开最大数的最大数，做个比较就可以了
### 代码
```mysql
# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary 
from Employee
 where Salary < (select max(Salary) from Employee)
```