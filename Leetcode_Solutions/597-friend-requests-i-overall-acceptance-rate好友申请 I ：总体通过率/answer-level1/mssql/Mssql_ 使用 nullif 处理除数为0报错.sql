```
SELECT convert(decimal(10, 2), isnull((
		SELECT COUNT(*) AS accepted_count
		FROM (
			SELECT DISTINCT requester_id, accepter_id
			FROM request_accepted
		) t2
	) * 1.0 / (
		SELECT nullif(COUNT(*),0) AS send_count
		FROM (
			SELECT DISTINCT sender_id, send_to_id
			FROM friend_request
		) t1
	), 0)) AS accept_rate
```
