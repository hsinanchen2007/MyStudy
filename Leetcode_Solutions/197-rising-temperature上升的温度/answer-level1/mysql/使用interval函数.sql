date型数据直接比较是错的 使用interval函数向昨天加一天，如果加之后的结果等于今天，
且温度条件满足。则正确：
```
select a.id as id from Weather a,Weather b 
where 
a.RecordDate=(b.RecordDate+interval 1 day) 
and 
a.Temperature>b.Temperature;`
```
