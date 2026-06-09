```
# Write your MySQL query statement below
SELECT round(SUM(CASE 
		WHEN b.event_date IS NOT NULL THEN 1
		ELSE NULL
	END) / COUNT(*), 2) AS fraction
FROM (
	SELECT player_id, MIN(event_date) AS event_date
	FROM Activity
	GROUP BY player_id
) a
	LEFT JOIN Activity b
	ON a.player_id = b.player_id
		AND date_add(a.event_date, INTERVAL 1 DAY) = b.event_date
```
