# Write your MySQL query statement below

select b.country_name, (case when a.temp<=15 then 'Cold'
when a.temp>=25 then 'Hot'
else 'Warm' end) as weather_type
from
(select country_id,avg(weather_state) as temp
from weather
where day between '2019-11-01' and '2019-11-30'
group by country_id) as a
inner join countries b
on a.country_id=b.country_id;