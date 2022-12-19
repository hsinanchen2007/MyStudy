```
SELECT
    employee_id,
    team_size
FROM
    Employee e
INNER JOIN
    (
        SELECT
            team_id,
            COUNT(*) AS team_size
        FROM
            Employee
        GROUP BY
            team_id
    ) AS t1
ON e.team_id = t1.team_id
```
