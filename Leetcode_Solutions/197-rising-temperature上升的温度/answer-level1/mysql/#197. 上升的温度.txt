```mysql
SELECT 
    lw.id AS 'Id'
FROM
    Weather lw
		JOIN
    Weather rw ON DATEDIFF(lw.RecordDate, rw.RecordDate) = 1
        AND lw.Temperature > rw.Temperature
;

```