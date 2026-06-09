
```MySQL []
SELECT t.request_at AS day, 
round(sum(if(t.status='completed',0,1))/count(t.status),2) AS 'cancellation rate'
FROM trips t LEFT JOIN users u
ON u.users_id = t.client_id
WHERE banned='no' AND (t.re[]()quest_at BETWEEN '2013-10-01' AND '2013-10-03')
GROUP BY t.request_at;
```
