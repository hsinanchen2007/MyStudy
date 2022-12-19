### 解题思路
先把between '2019-11-01' and '2019-11-30'的纪录挑出来，按照country_id分组，算出平均温度，列成一个新的column（avgw），只选这个列和country_id列为表a，再和countries表相连，取国家名字。weather_type这里用case when。
### 代码

```mysql
# Write your MySQL query statement below\
select c.country_name, (case when avgw <= 15 then 'Cold' when avgw >= 25 then 'Hot' else 'Warm' end) as weather_type
from (select country_id,avg(weather_state)avgw
from weather 
where day between '2019-11-01' and '2019-11-30'
group by country_id) a 
join countries c on a.country_id = c.country_id
group by c.country_name



```