### 解题思路
where 里面限制tiv—2015 count大于一次，(lat,lon) count 等于一次

### 代码

```mysql
# Write your MySQL query statement below


select sum(tiv_2016) tiv_2016
from insurance
where tiv_2015 in (
    select tiv_2015
    from insurance
    group by tiv_2015
    having count(*)>1
) and (lat,lon) in (
    select lat,lon
    from insurance
    group by lat,lon
    having count(*)=1
)

    









```