论性能，解法3 > 解法2 > 解法1；但解法1更易理解。   

解法1（exists）：
`where`子句中使用`exists`实现关联子查询，筛选满足条件的观测
```mysql
select round(sum(a.TIV_2016), 2) TIV_2016
from insurance a
where exists (select b.PID
              from insurance b
              where a.PID != b.PID
                and a.TIV_2015 = b.TIV_2015)    -- cond1: 在2015年投保额至少跟一个其他人相同
    and not exists (select b.PID
                    from insurance b
                    where a.PID != b.PID
                        and a.lon = b.lon and a.lat = b.lat);    -- cond2: 经纬度不能跟其他任何人相同

```

解法2（left join）：
使用连接，筛选满足条件的观测
```mysql
select round(sum(tmp1.TIV_2016), 2) TIV_2016
from 
(select distinct a.PID, a.TIV_2016
 from insurance a 
    join insurance b on a.PID != b.PID
 where a.TIV_2015 = b.TIV_2015) tmp1    -- cond1

left join 

(select distinct a.PID
 from insurance a
    join insurance b on a.PID != b.PID
 where a.lon = b.lon and a.lat = b.lat) tmp2 on tmp1.PID = tmp2.PID    -- cond2的逆，排除

where tmp2.PID is null;  

```

解法3（group by和count）：
使用`group by`,在`having`子句中使用聚合函数`count` ，确定出现2次以上的2015年投保额（等价于某投保人在2015年的投保额至少与一个其他人的相同），经纬度的取值只能出现一次。
```mysql
select round(sum(TIV_2016), 2) TIV_2016
from insurance 
where TIV_2015 in (select TIV_2015
                   from insurance
                   group by TIV_2015
                   having count(*) >= 2)    -- cond1
    and concat(lon, lat) in (select concat(lon, lat)
                             from insurance
                             group by concat(lon, lat)
                             having count(*) = 1);    -- cond2
```