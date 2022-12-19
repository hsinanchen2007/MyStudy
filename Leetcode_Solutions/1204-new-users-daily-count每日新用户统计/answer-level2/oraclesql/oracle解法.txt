```
SELECT to_char(activity_date,'yyyy-MM-dd') AS login_date, COUNT(*) AS user_count
FROM (
	SELECT a.user_id, a.activity, a.activity_date, row_number() OVER (PARTITION BY user_id ORDER BY activity_date) AS rk
	FROM Traffic a where a.activity  = 'login'
) a
WHERE a.rk = 1
	AND to_date('2019-06-30','yyyy-MM-dd') - a.activity_date <= 90
GROUP BY activity_date order by activity_date
```

第二种

```
SELECT to_char(activity_date,'yyyy-MM-dd') AS login_date, COUNT(*) AS user_count
FROM (
	SELECT a.user_id, MIN(activity_date) AS activity_date
	FROM Traffic a
	WHERE a.activity = 'login'
	GROUP BY a.user_id
) a
WHERE to_date('2019-06-30', 'yyyy-MM-dd') - a.activity_date <= 90
GROUP BY activity_date
ORDER BY activity_date
```

