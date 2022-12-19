### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select sum(TIV_2016) as TIV_2016 from
(select TIV_2015, count(PID) as money_times
from insurance group by 1) as lhs
right join
(select PID, TIV_2015, TIV_2016, concat(LAT,' ',LON) as location from insurance) as i1
on lhs.TIV_2015 = i1.TIV_2015
left join
(select concat(LAT,' ', LON) as location, count(PID) as location_times from insurance
group by 1) as rhs
on i1.location = rhs.location
where money_times > 1 and location_times = 1

```