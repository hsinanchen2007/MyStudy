### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below



select sum(d.TIV_2016) as TIV_2016 
from insurance d
where d.PID in
(
    select distinct a.PID 
from insurance a inner join insurance b
on a.TIV_2015 = b.TIV_2015 and a.PID <> b.PID
where (a.LAT,a.LON) NOT IN (
    select c.LAT ,c.LON from insurance c
    where c.PID <>a.PID
) 
) 
```