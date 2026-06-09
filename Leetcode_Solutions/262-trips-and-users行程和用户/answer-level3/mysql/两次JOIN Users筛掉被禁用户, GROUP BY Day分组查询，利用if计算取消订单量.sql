```sql
SELECT
    Request_at AS Day,
    round(
        count(if(
                    Status='cancelled_by_driver' OR Status='cancelled_by_client',
                    Id, null
                ))
    / count(Id) 
        , 2) AS 'Cancellation Rate'
FROM 
    Trips 
    JOIN Users client ON (client.Users_Id = Trips.Client_Id) AND client.Banned != "Yes"
    JOIN Users driver ON (driver.Users_Id = Trips.Driver_Id) AND driver.Banned != "Yes"
GROUP BY Day
HAVING Day BETWEEN '2013-10-01' AND '2013-10-03'
ORDER BY Day;
```