用变量还是可以，挺好的
```
# Write your MySQL query statement below

SELECT b.Name as Department , a.Name as Employee, a.Salary 
FROM (
	SELECT a.*
		, CASE 
			WHEN a.DepartmentId = @preCol THEN 
				CASE 
					WHEN a.Salary = @preSala THEN @rk
					ELSE @rk := @rk + 1
				END
			ELSE @rk := 1
		END AS rk, @preCol := a.DepartmentId, @preSala := a.Salary
	FROM Employee a, (
			SELECT @preCol := NULL, @preSala := 0
				, @rk := 0
		) s
	ORDER BY a.DepartmentId, Salary DESC
) a join Department b on a.DepartmentId  = b.Id
WHERE a.rk <= 3
```
