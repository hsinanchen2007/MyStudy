```
/* Write your PL/SQL query statement below */
SELECT round(SUM(CASE 
		WHEN event_date + 1 = nextDate THEN 1
		ELSE NULL
	END) / COUNT(*), 2) AS fraction
FROM (
	SELECT player_id, event_date, lead(event_date, 1) OVER (PARTITION BY player_id ORDER BY event_date) AS nextDate
		, row_number() OVER (PARTITION BY player_id ORDER BY event_date) AS rk
	FROM Activity
) a
WHERE rk = 1
```
