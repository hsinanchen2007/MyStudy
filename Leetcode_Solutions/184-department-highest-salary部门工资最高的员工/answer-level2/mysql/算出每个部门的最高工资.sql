### 解题思路
先算出每个部门的最高工资,
然后联合多表查查询结果
### 代码

```mysql
# Write your MySQL query statement below
SELECT
	b.`Name` AS "Department",
	a.`Name` AS "Employee",
	a.Salary as Salary
FROM
	Employee AS a,
	Department as b,
	(SELECT MAX(Salary) as Salary,DepartmentId FROM Employee GROUP BY DepartmentId) AS c
WHERE
 c.Salary = a.Salary AND a.DepartmentId = b.Id AND b.Id = c.DepartmentId

```