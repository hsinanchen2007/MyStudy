```sql
SELECT ROUND(IFNULL(AVG(count_session_id), 0), 2) AS average_sessions_per_user
FROM
(
SELECT COUNT(DISTINCT session_id) AS count_session_id
FROM Activity
WHERE activity_date
BETWEEN DATE_SUB("2019-07-27", INTERVAL 29 DAY) AND "2019-07-27"
GROUP BY user_id
) AS temp;
```