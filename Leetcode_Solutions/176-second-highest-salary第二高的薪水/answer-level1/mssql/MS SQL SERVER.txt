select NULLIF((SELECT
	Salary
FROM
	(
		SELECT
			Salary,
			row_number () OVER (ORDER BY Salary DESC) AS rn
		FROM
			(SELECT DISTINCT Salary FROM
			Employee) g
	) a
WHERE
	rn = 2),NULL)  AS SecondHighestSalary