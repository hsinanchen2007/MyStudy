### 解题思路
先找第一大数 再在表里找小于第一大数的数

### 代码

```mysql
# Write your MySQL query statement below
# 先求最小薪水
-- select max(Salary) SecondHighestSalary  from Employee e
-- join Employee e2 on e2.Salary > e.SecondHighestSalary
SELECT max(Salary) SecondHighestSalary
 FROM Employee  
where Salary < (select max(Salary) from Employee );
```