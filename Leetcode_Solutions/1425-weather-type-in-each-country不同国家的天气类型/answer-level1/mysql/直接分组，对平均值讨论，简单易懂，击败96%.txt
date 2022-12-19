## 无需子查询
```
select country_name, 
        case 
            when avg(weather_state) <= 15 then 'Cold'
            when avg(weather_state) >= 25 then 'Hot'
            else 'Warm'
        end
        as weather_type
from Countries, Weather 
where Countries.country_id = Weather.country_id and day between '2019-11-01' and '2019-11-30'
group by Countries.country_id
```