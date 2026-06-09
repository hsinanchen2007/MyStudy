### 解题思路
加个有效数字

### 代码

```mysql
# Write your MySQL query statement below


select round(sum(TIV_2016),2) TIV_2016
from insurance i 
where TIV_2015 in (
    select TIV_2015
    from insurance
    group by TIV_2015
    having count(*)>1
)  and (LAT,LON) in (
    select LAT,LON
    from insurance
    group by LAT,LON
    having count(*)=1
)

```