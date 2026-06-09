```sql
SELECT t.Request_at Day,
    ROUND(COUNT(IF(t.status!='completed',TRUE,NULL)) / COUNT(*), 2)
        AS 'Cancellation Rate'
FROM trips AS t
WHERE t.client_id IN (SELECT users_id FROM users WHERE Banned='No')
    AND t.driver_id IN (SELECT users_id FROM users WHERE Banned='No')
    AND t.request_at BETWEEN '2013-10-01' and '2013-10-03'
GROUP BY t.request_at;
```
