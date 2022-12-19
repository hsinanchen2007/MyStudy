### 解题思路


1.排除Employee中bonus>=1000得员工;
2.合并Bonus和Employee展示name 和 bonus

### 代码

```mysql
# Write your MySQL query statement below

SELECT E0.name, B0.bonus
FROM (
    SELECT E.empId as empId, E.name as name  from Employee E WHERE E.empId not in 
        (SELECT B.empId as empId FROM Bonus B WHERE Bonus>=1000)
  ) E0
LEFT JOIN Bonus B0
ON B0.empId = E0.empId
```
