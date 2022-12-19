### 解题思路
1.按照用户和日期排序，计算首次登陆日期 first_date 和 每条记录与首次登陆日期差 date_diff
2.汇总date_diff = 1的用户去重/总用户去重
3.round取两位小数

### 执行结果
执行用时 :320 ms, 在所有 MySQL 提交中击败了28.08%的用户


### 代码

```mysql
# Write your MySQL query statement below

SELECT round(COUNT(DISTINCT if(date_diff = 1, player_id, NULL)) / COUNT(DISTINCT player_id), 2) AS fraction
FROM (
	SELECT player_id
		, @first_date := if(@last_user IS NULL
			OR @last_user <> player_id, event_date, @first_date)
		, datediff(event_date, @first_date) AS date_diff
		, @last_user := player_id
	FROM Activity, (
			SELECT @first_date := NULL, @last_user := NULL
		) temp
	ORDER BY player_id, event_date ASC
) a
```