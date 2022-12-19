思路：

分为三步：

1、用exists子句，找到insurance表中当前投保人与其他投保人2015年投资额的相同的所有记录；

2、用not exists子句，再排除掉insurance表中当前投保人与其他投保人所在城市经度与维度完全相同的记录；

3、最后对筛选后满足条件的剩余记录的2016年投资额累计求和即可。
```
select round(sum(A.TIV_2016),2) as TIV_2016
from insurance A
where exists(
    select * from insurance B where B.PID<>A.PID and B.TIV_2015=A.TIV_2015
) and not exists(
    select * from insurance C where C.PID<>A.PID and C.LAT=A.LAT and C.LON=A.LON
)
```
执行用时 :847 ms, 内存消耗 :0B