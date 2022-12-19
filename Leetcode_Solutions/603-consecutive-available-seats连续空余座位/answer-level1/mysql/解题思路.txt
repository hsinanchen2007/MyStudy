### 解题思路
因为题目是两个连续，最简单的还是自关联；
下面使用另一种解决方法：
1.正序给所有记录标上是第几条连续 free_count
2.倒序判断当free_count>1或者free_count=1且上一条的free_count>1时，标记连续 cas
3.正序取出所有cas=1的记录  

>然而执行的并不快
>执行用时 :160 ms, 在所有 mysql 提交中击败了6.70%的用户
### 代码

```mysql
# Write your MySQL query statement below

SELECT seat_id
FROM (
	SELECT seat_id
		, if(free_count > 1
			OR (free_count = 1
				AND @last_free_count > 1), 1, 0) AS cas
		, @last_free_count := free_count
	FROM (
		SELECT seat_id, free
			, @free_count := if(free = 1, @free_count + 1, 0) AS free_count
		FROM cinema, (
				SELECT @free_count := 0
			) temp1
		ORDER BY seat_id ASC
	) a, (
			SELECT @last_free_count := 0
		) temp2
	ORDER BY seat_id DESC
) b
WHERE cas = 1
ORDER BY seat_id ASC
```