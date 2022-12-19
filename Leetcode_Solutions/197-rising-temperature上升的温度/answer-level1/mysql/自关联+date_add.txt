 ```
select w1.Id from Weather as w1 join Weather as w2 on w1.RecordDate=date_add(w2.RecordDate,interval 1 day) where w1.Temperature > w2.Temperature 
```
