```
/* Write your PL/SQL query statement below */
SELECT a.player_id, b.device_id
FROM Activity b
	JOIN (
		SELECT player_id, MIN(event_date) AS first_login
		FROM Activity
		GROUP BY player_id
	) a
	ON a.player_id = b.player_id
		AND a.first_login = b.event_date
```
