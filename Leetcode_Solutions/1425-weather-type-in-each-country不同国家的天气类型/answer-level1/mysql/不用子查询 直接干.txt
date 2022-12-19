### 解题思路
主要就是case费点劲 其他的都是常规的一些操作
### 代码

```mysql
# Write your MySQL query statement below

select c.country_name `country_name`,
case when round(sum(case when w.day between '2019-11-01' and '2019-11-30' then w.weather_state else 0 end)/sum(case when w.day between '2019-11-01' and '2019-11-30' then 1 else 0 end),3) <= 15 then 'Cold' else 
case when round(sum(case when w.day between '2019-11-01' and '2019-11-30' then w.weather_state else 0 end)/sum(case when w.day between '2019-11-01' and '2019-11-30' then 1 else 0 end),3) >= 25 then 'Hot' else 'Warm' end end as weather_type 
from Countries c left join Weather w on c.country_id = w.country_id and w.day between '2019-11-01' and '2019-11-30' 
where w.day is not null  group by w.country_id  
```