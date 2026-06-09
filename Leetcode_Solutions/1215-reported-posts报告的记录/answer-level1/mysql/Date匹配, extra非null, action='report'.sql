```sql
SELECT extra AS report_reason, COUNT(DISTINCT post_id) AS report_count 
FROM Actions 
WHERE DATE(action_date) = DATE_SUB("2019-07-05",INTERVAL 1 DAY)
    AND extra IS NOT null 
    AND action = 'report' 
GROUP BY extra;
```