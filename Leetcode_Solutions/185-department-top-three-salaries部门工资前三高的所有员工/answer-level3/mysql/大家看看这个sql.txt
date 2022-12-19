```mysql
SELECT
	d. NAME AS department,
	t. NAME AS employee,
	t.salary
FROM
	(
		SELECT
			a.*
		FROM
			employee a
		LEFT JOIN employee b ON a.departmentid = b.departmentid
		AND a.salary < b.salary
		GROUP BY
			a.id
		HAVING
			count(distinct b.salary) < 3
	) t
JOIN department d ON t.departmentid = d.id
ORDER BY
	t.departmentid ASC,
	salary DESC;
```
