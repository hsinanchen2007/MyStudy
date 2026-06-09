### 解题思路
多嵌套一层select就可以把无结果变成返回一个null

### 代码

```mysql
# Write your MySQL query statement below
Select (SELECT   DISTINCT  Salary
FROM Employee
ORDER BY Salary DESC
LIMIT 1
OFFSET 1
) As SecondHighestSalary ;

```