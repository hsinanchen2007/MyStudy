### 几个条件：
#### 1. users.banned='No'， 要注意 client_id和driver_id 都要满足
#### 2. trips.request_at between '2013-10-01' and '2013-10-03' 
```
SELECT
	t.request_at `Day`,
	ROUND( SUM( IF ( t.`status` = 'completed', 0, 1 ) ) / COUNT( t.`status` ), 2 ) `Cancellation Rate` 
FROM
	trips t
	JOIN users u1 ON t.client_id = u1.users_id AND u1.banned = 'No'
	JOIN users u2 ON t.driver_id = u2.users_id AND u2.banned = 'No' 
WHERE
	t.request_at BETWEEN '2013-10-01' AND '2013-10-03' 
GROUP BY
	t.request_at;
```
