```
# Write your MySQL query statement below
SELECT a.project_id,a.employee_id   
FROM (
	SELECT a.*
		, CASE 
			WHEN @prevCol = project_id THEN 
				CASE 
					WHEN @prevCol2 = experience_years THEN @curRank := @curRank
					ELSE @curRank := @curRank + 1
				END
			ELSE @curRank := 1
		END AS rk, @prevCol := project_id, @prevCol2 := experience_years
	FROM (
		SELECT a.*, b.experience_years
		FROM Project a
			LEFT JOIN Employee b ON a.employee_id = b.employee_id
	) a, (
			SELECT @curRank := 1, @prevCol := NULL
				, @prevCol2 := NULL
		) r
	ORDER BY a.project_id, a.experience_years DESC
) a
WHERE a.rk = 1
```
