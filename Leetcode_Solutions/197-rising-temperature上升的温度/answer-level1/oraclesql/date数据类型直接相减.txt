```
SELECT b.id FROM Weather a ,Weather b
WHERE a.RecordDate+1 = b.RecordDate
and a.Temperature < b.Temperature
```
