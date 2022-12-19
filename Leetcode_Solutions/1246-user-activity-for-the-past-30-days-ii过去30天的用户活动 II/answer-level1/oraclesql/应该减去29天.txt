注意：题目说30天，那么应该减去29天，我开始减30天错了，确实应该减去29天。
1、第一种方式感觉自己蠢.....
```
/* Write your PL/SQL query statement below */
SELECT decode(COUNT(DISTINCT a.user_id),0,0,round(COUNT(*)/COUNT(DISTINCT a.user_id), 2)) AS average_sessions_per_user
FROM (
	SELECT a.user_id, a.session_id
	FROM Activity a
	WHERE a.activity_date <= to_date('2019-07-27', 'yyyy-MM-dd')
		AND a.activity_date >= to_date('2019-07-27', 'yyyy-MM-dd') - 29
	GROUP BY a.user_id, a.session_id
) a
```


2、增加第二种
```
# Write your MySQL query statement below

SELECT ifnull(round(COUNT(DISTINCT a.session_id) / COUNT(DISTINCT user_id), 2), 0) AS average_sessions_per_user
FROM Activity a
WHERE datediff('2019-07-27', a.activity_date) < 30
```
