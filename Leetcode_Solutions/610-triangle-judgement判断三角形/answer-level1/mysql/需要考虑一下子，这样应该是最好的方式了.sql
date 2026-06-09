```
/* Write your PL/SQL query statement below */
SELECT x, y, z
	, CASE 
		WHEN x + y + z > 2 * greatest(x, y, z) THEN 'Yes'
		ELSE 'No'
	END as triangle 
FROM triangle
```
