
```
SELECT b.Name AS Department, a.name AS Employee, a.Salary
FROM (
	SELECT Id, Name, Salary, DepartmentId
	FROM (
		SELECT Id, Name, Salary, DepartmentId, DENSE_RANK() OVER (PARTITION BY DepartmentId ORDER BY Salary DESC) AS rk
		FROM Employee
	) a
	WHERE a.rk <= 3
) a
	LEFT JOIN Department b ON a.DepartmentId = b.Id 
WHERE b.Id IS NOT NULL

```
