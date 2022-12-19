INTERVAL这里得写的是29天

```sql
SELECT activity_date AS day, COUNT(distinct user_id) AS active_users
FROM Activity
WHERE activity_date 
BETWEEN DATE_SUB("2019-07-27", INTERVAL 29 DAY) AND "2019-07-27"
GROUP BY activity_date
HAVING COUNT(distinct user_id) <> 0;
```