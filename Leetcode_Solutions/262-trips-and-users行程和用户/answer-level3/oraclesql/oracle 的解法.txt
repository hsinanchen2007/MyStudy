```
/* Write your PL/SQL query statement below */
SELECT Request_at AS Day, ROUND(cancelCount / allNum, 2) AS "Cancellation Rate"
FROM (
	SELECT COUNT(CASE 
			WHEN instr(Status, 'cancelled') > 0 THEN 1
			ELSE NULL
		END) AS cancelCount, COUNT(*) AS allNum, Request_at
	FROM (
		SELECT a.*
		FROM (
			SELECT *
			FROM Trips a
			WHERE a.Request_at >= '2013-10-01'
				AND a.Request_at <= '2013-10-03'
		) a
			LEFT JOIN Users b ON (a.Client_Id = b.Users_Id
			AND b.Banned = 'Yes')
		OR (a.Driver_Id = b.Users_Id
			AND b.Banned = 'Yes') 
		WHERE b.Users_Id IS NULL
	) c
	GROUP BY Request_at
)
```
