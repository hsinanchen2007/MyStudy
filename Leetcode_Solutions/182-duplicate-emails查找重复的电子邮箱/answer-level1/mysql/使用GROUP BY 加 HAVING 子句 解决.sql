要寻找重复数据，要先对数据进行分组。比如这道题目，就需要对Email进行分组，如果同一组有超过两条数据，则这种数据满足条件。
Tips：where子句在Group by 之前，Having子句在Group by 之后；```
select Email from Person group by Email having count(*)>1
```
