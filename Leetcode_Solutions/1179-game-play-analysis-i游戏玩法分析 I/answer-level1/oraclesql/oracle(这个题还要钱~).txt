```
SELECT player_id, MIN(to_char(event_date, 'yyyy-MM-dd')) AS first_login
FROM Activity
GROUP BY player_id
```
