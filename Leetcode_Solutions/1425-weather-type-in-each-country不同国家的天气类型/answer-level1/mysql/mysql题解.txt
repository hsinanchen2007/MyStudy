/*select C.country_name country_name,
(case when sum(W.weather_state)/count(W.weather_state)<=15 then "Cold"
      when sum(W.weather_state)/count(W.weather_state)>=25 then "Hot"
      else "Warm"
  end)weather_type
from Countries C,Weather W
where C.country_id=W.country_id and W.day between "2019-11-01" and "2019-11-30"
group by W.country_id
*/

select C.country_name country_name,
(case when avg(W.weather_state)<=15 then "Cold"
      when avg(W.weather_state)>=25 then "Hot"
      else "Warm"
  end)weather_type
from Countries C,Weather W
where C.country_id=W.country_id and W.day between "2019-11-01" and "2019-11-30"
group by W.country_id
