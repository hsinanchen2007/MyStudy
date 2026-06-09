 日期 day 的筛选我试了 between and ,但是速度比 like 语句慢。 


```
select country_name, 
case when avg(weather_state)<= 15 then 'Cold'
    when avg(weather_state)>= 25 then 'Hot' 
    else 'Warm'
end as weather_type
from countries c
join weather w 
on c.country_id=w.country_id
where day like'2019-11%'  
group by country_name; 

```
