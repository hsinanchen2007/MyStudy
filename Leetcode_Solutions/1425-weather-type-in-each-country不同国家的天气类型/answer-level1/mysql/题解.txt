```
select country_name,
(case when avg(weather_state)<=15 then 'Cold' when avg(weather_state)>=25 then 'Hot' else 'Warm' end) weather_type 
from Countries a
    join Weather b
        on a.country_id = b.country_id 
            and b.day >='2019-11-01' 
            and b.day < '2019-12-01'
group by a.country_id
```
