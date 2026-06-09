select Department,Employee,Salary from (SELECT
  d.Name Department,
	e.Name Employee,
	Salary,
	DENSE_RANK () OVER (
		partition BY DepartmentId
		ORDER BY
			Salary DESC
	) AS rn
FROM
	Employee e INNER JOIN Department d on e.DepartmentId=d.Id) as em where   rn<=3 