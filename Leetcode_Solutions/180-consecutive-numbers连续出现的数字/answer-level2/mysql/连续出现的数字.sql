##### 解题思路
先在子查询中统计相同数字的个数，在通过where查出符合条件的数字
### 代码
```mysql
# Write your MySQL query statement below
SELECT
DISTINCT
	ConsecutiveNums
FROM
	(
		SELECT
			Num as ConsecutiveNums,@pre :=
		IF (@cur = Num ,@pre + 1 ,@pre := 1) AS coun ,@cur := Num
		FROM
			Logs,
			(SELECT @pre := 1 ,@cur := NULL) r
		
	) s
WHERE
	coun > 2
```
