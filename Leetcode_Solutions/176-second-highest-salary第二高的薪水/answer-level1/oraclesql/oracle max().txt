### 解题思路
排除第一高，取max(salary)

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
where salary < ( SELECT MAX(Salary) FROM Employee )
```