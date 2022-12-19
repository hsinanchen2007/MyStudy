```
/* Write your PL/SQL query statement below */

SELECT distinct Num as ConsecutiveNums
FROM (
    SELECT Id, Num
        , lead(ID, 2, -1) OVER (PARTITION BY Num ORDER BY id) AS id2
    FROM Logs
) a
WHERE a.id2 = a.id + 2
```
