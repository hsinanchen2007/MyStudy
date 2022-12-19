```
SELECT extra report_reason,COUNT(DISTINCT post_id) report_count
FROM Actions
WHERE action_date='2019-07-04' AND action='report'
GROUP BY extra
HAVING report_reason IS NOT NULL;
```
第一次忘记动作需要是report，审题不仔细啊