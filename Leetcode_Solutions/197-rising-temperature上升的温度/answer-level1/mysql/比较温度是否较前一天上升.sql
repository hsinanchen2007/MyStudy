```
select w1.Id from Weather w1 INNER JOIN Weather w2 on DATE_SUB(w1.RecordDate, INTERVAL 1 DAY) = w2.RecordDate where w1.Temperature>w2.Temperature;
```
