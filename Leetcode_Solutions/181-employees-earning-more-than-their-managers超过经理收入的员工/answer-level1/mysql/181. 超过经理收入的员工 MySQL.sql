### 解题思路
1.因为是找到比自己经理收入高的员工共姓名，因此需要表与自身做连接，找到自己对应的经理。
2.在做限制条件，使员工的收入比经理高。

### 代码

```mysql
# Write your MySQL query statement below

SELECT a.Name AS Employee
FROM Employee AS a JOIN Employee AS b ON a.ManagerId = b.Id
AND a.Salary > b.Salary;
```