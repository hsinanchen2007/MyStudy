### 解题思路
首先进行左联结并在条件中筛选出11月份的数据，考虑到可以存在没有温度数据的国家所以要把null值去掉。然后使用avg()和case when进行分类


### 代码

```mysql
# Write your MySQL query statement below
select a.country_name,
     case when avg(b.weather_state)<=15 then 'Cold'
	 when avg(b.weather_state)>=25 then 'Hot'
	 else 'Warm' end as weather_type
from countries a
left join weather b
on a.country_id=b.country_id
and b.day>='2019-11-01'
and b.day<='2019-11-30'
where b.weather_state is not null
group by a.country_name
```