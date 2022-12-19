```
select distinct tb1.Email from Person tb1 
join Person tb2 on tb1.Email=tb2.Email and tb2.Id != tb1.Id
```
同表inner join 取交集(email相同，id不同)，去重