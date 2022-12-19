
此题的思路在于成功投资的条件，不复杂，就是在满足第二个条件的情况下注意不要过滤掉相同的经纬度记录，相同的经纬度的记录中的投保额可能用在第一个条件中
采用oracle开窗
```
SELECT round(SUM(a.TIV_2016), 2) AS TIV_2016
FROM (
	SELECT a.*, COUNT(*) OVER (PARTITION BY TIV_2015 ) AS sameTIV
	FROM (
		SELECT a.*, COUNT(*) OVER (PARTITION BY LAT, LON ) AS dulicateNums
		FROM insurance a
	) a
) a
WHERE A.sameTIV > 1
	AND A.dulicateNums = 1
```
