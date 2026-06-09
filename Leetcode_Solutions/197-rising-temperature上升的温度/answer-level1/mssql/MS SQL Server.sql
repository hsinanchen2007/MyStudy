

```
select b.Id from Weather a, Weather b where DATEDIFF(day, a.RecordDate, b.RecordDate)=1 and a.Temperature<b.Temperature

```
**或者**

```
select b.Id from Weather a inner JOIN Weather b ON DATEDIFF(day, a.RecordDate, b.RecordDate)=1 and a.Temperature<b.Temperature
```
