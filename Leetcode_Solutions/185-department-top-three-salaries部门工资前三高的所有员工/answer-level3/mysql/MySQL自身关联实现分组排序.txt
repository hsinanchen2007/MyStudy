解题思路写在博客中：https://my.oschina.net/siwcky90/blog/3147328

答案:
```
SELECT
	de.name AS Department,
	em.name AS Employee,
	em.Salary AS Salary
FROM
	(
		SELECT
			a.Name,
			a.Salary,
			a.DepartmentId,
			COUNT(DISTINCT b.Salary) AS rn
		FROM
			Employee a
		LEFT JOIN Employee b
		ON
			a.DepartmentId = b.DepartmentId
			AND a.Salary <= b.Salary
		GROUP BY
			a.Name,
			a.Salary,
			a.DepartmentId
		ORDER BY
			a.DepartmentId,
			a.Salary DESC
	)
	em
INNER JOIN Department de
ON
	em.DepartmentId = de.id
WHERE
	em.rn <= 3
ORDER BY
	em.DepartmentId,
	em.Salary DESC
```
