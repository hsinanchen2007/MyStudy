### 解题思路
1.给Salary表降序排序，选择第二行内容即，第二高的薪水
2.因为可能会有单条工资条，因此会返回空值的Salary，因此要建立临时表来返回null值

### 代码

```mysql
# Write your MySQL query statement below
SELECT
(SELECT DISTINCT Salary
FROM Employee
ORDER BY Salary DESC
LIMIT 1 OFFSET 1) AS SecondHighestSalary;