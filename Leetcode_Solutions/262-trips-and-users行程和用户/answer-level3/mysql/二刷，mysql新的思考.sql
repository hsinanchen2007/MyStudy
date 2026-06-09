```
# Write your MySQL query statement below

SELECT Request_at AS Day
	, round(COUNT(CASE 
		WHEN Status != 'completed' THEN 1
		ELSE NULL
	END) / COUNT(*), 2) AS "Cancellation Rate"
FROM (
	SELECT a.Id, MAX(Status) AS Status, MAX(Request_at) AS Request_at
	FROM Trips a
		JOIN Users b
		ON ((a.Client_Id = b.Users_Id
				OR a.Driver_Id = b.Users_Id)
			AND b.Banned = 'No'
			AND a.Request_at >= '2013-10-01'
			AND a.Request_at <= '2013-10-03')
	GROUP BY a.Id
	HAVING COUNT(*) = 2
) a
GROUP BY Request_at
```
