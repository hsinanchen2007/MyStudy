```
# Write your MySQL query statement below
select 
    c.country_name,
    (case when avg(cast(w.weather_state as signed))<=15 then 'Cold'
    when avg(cast(w.weather_state as signed))>=25 then 'Hot'
    else 'Warm'
    end) as weather_type
from 
    Countries c inner join Weather w 
on 
    c.country_id=w.country_id
where 
    date_format(w.day,'%Y-%m')='2019-11'
group by 
    c.country_name
order by 
    c.country_id
```
