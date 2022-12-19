### 执行用时
157 ms

### 解题思路
与昨天日期相比温度更高 => datediff(curr_D, last_D) = 1 and curr_T > last_T

### 代码

```mysql
# Write your MySQL query statement below
SELECT a.Id
FROM (
	SELECT w.Id, w.Temperature
		, if(w.Temperature > @last_T
			AND datediff(w.RecordDate, @last_D) = 1, 1, 0) AS is_greater
		, @last_T := w.Temperature, @last_D := w.RecordDate
	FROM Weather w, (
			SELECT @last_T := 100, @last_D := 1
		) b
	ORDER BY RecordDate ASC
) a
WHERE a.is_greater = 1
ORDER BY a.Id ASC
```

第一次失败：id递增，日期不一定
第二次失败：日期不一定连续
测试用例很重要