### 解题思路
去重，查找某一条limit,解决null用了IFNULL()函数，临时表

### 代码

```mysql
# Write your MySQL query statement below


SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary

```