### 解题思路
去掉最高找最高就是第二

### 代码

```mysql
# Write your MySQL query statement below

select max(Salary) SecondHighestSalary
from Employee
where Salary <> (select max(Salary) from Employee );


SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary

```