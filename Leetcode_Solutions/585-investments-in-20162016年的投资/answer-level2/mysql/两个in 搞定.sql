
按照2015的投资分组，筛选出有相同人投资的 投资额度
```
SELECT t0.`TIV_2015`,COUNT(1)
FROM `insurance` t0
GROUP BY t0.`TIV_2015`
HAVING COUNT(1)>1

```
TIV_2015  count(1)  
--------  ----------
10.00              3


按照经纬度分组，查出地理位置唯一的经纬度
```
SELECT t2.`LAT`,t2.`LON`
FROM 
`insurance` t2
GROUP BY t2.`LAT`,t2.`LON`
HAVING COUNT(1)=1
```



结果满足2015年投资与别人相同，且城市经纬度唯一
```
SELECT SUM(t1.`TIV_2016`) TIV_2016 
FROM `insurance` t1
WHERE t1.`TIV_2015` IN 
(

SELECT t0.`TIV_2015`
FROM `insurance` t0
GROUP BY t0.`TIV_2015`
HAVING COUNT(1)>1
) AND 

(t1.`LAT`,t1.`LON` )IN 
(
SELECT t2.`LAT`,t2.`LON`
FROM 
`insurance` t2
GROUP BY t2.`LAT`,t2.`LON`
HAVING COUNT(1)=1
)

```
