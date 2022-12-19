### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
SELECT b.Name Department ,a.Name Employee ,a.Salary Salary 
FROM Employee a LEFT JOIN Department b ON a.DepartmentId=b.Id 
WHERE ( a.DepartmentId, a.Salary ) IN (SELECT DepartmentId, max( Salary ) FROM Employee GROUP BY DepartmentId ) AND b.Name IS NOT NULL;
```