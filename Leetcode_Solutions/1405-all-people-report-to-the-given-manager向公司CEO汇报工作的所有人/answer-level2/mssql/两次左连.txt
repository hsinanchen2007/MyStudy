```
SELECT e.employee_id
FROM Employees e
	LEFT JOIN Employees ee ON e.manager_id = ee.employee_id
	LEFT JOIN Employees eee ON ee.manager_id = eee.employee_id
WHERE e.employee_id <> 1
	AND eee.manager_id = 1
```
