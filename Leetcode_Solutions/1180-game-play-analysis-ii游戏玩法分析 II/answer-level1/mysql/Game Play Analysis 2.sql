```
SELECT 
	a.player_id,a.device_id 
FROM 
	Activity AS a
JOIN
	(SELECT 
        player_id,MIN(event_date) AS latest_date 
	FROM 
        Activity 
	GROUP BY 
        player_id) AS b 
ON 
	a.event_date = b.latest_date
AND
	a.player_id = b.player_id
;
```
