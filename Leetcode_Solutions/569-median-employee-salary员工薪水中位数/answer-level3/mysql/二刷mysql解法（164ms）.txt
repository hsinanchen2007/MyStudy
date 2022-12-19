mysql这种解法的话效率还可以
```
# Write your MySQL query statement below

SELECT a.Id, a.Company, a.Salary
FROM (
	SELECT Id, Company, Salary
		, CASE 
			WHEN @preColm = Company THEN @rk := @rk + 1
			ELSE @rk := 1
		END AS rk, @preColm := Company
	FROM Employee a, (
			SELECT @preColm := NULL, @rk := 0
		) s
	ORDER BY Company, Salary
) a
	LEFT JOIN (
		SELECT Company, COUNT(*) AS nums
		FROM Employee
		GROUP BY Company
	) b
	ON a.Company = b.Company
WHERE CASE 
	WHEN b.nums % 2 = 0 THEN 
		CASE 
			WHEN b.nums / 2 = rk
			OR b.nums / 2 + 1 = rk THEN true
			ELSE false
		END
	ELSE 
		CASE 
			WHEN FLOOR(b.nums / 2) + 1 = rk THEN true
			ELSE false
		END
END
```
