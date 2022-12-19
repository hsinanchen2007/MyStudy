```
SELECT
	* 
FROM
	employee;
SELECT
	* 
FROM
	employee AS l1,
	employee AS l2;
SELECT
	* 
FROM
	employee AS l1,
	employee AS l2 
WHERE
	l1.ManagerId = l2.Id 
	AND l1.Salary > l2.Salary;
	
	
SELECT
	l1.`Name` as Employee
FROM
	employee AS l1,
	employee AS l2 
WHERE
	l1.ManagerId = l2.Id 
	AND l1.Salary > l2.Salary;
```
