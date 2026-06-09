```
SELECT
  a.Id
FROM
  Weather AS a
  JOIN Weather AS we
    ON a.RecordDate = ADDDATE(we.RecordDate, 1)
    AND a.Temperature > we.Temperature
```