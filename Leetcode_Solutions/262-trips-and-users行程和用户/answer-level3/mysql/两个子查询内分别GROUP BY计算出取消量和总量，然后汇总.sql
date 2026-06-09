```sql
SELECT t1.Day AS Day,
    /*t2.Cancelled, t1.Total,*/ 
    round(IFNULL(t2.Cancelled,0.0)/t1.Total,2) AS 'Cancellation Rate'
FROM (
    SELECT Request_at Day, COUNT(Id) Total
    FROM Trips t1
    WHERE (
        Driver_Id NOT IN (SELECT Users_Id FROM Users WHERE Role='driver' AND Banned='Yes') 
        AND Client_Id NOT IN (SELECT Users_Id FROM Users WHERE Role='client' AND Banned='Yes')
    )
    GROUP BY Day
    HAVING Day BETWEEN '2013-10-01' AND '2013-10-03'
) t1
LEFT JOIN (
    SELECT Request_at Day, COUNT(Id) Cancelled
    FROM Trips
    WHERE (Status="cancelled_by_driver" OR Status="cancelled_by_client")
          AND ( 
              Driver_Id NOT IN (SELECT Users_Id FROM Users WHERE Role='driver' AND Banned='Yes') 
              AND 
              Client_Id NOT IN (SELECT Users_Id FROM Users WHERE Role='client' AND Banned='Yes')
          )
    GROUP BY Day
    HAVING Day BETWEEN '2013-10-01' AND '2013-10-03'
) t2 ON t1.Day=t2.Day
ORDER BY Day
```