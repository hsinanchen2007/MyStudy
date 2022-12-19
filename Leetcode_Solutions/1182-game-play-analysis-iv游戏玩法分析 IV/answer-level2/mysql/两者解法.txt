[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

本题有个坑点，首次登录后，紧接着第二天又登录的人数占总人数的比例。

# 解法一
第一步要明确每个人首次登录的时间。用group by完成。
```
(
SELECT player_id, MIN(event_date) AS `date`
FROM Activity
GROUP BY player_id
) AS C
```
表activity与表C连接，排除掉日期不是首次登录日的行。
```
SELECT *
FROM Activity AS A
JOIN (
    SELECT player_id, MIN(event_date) AS `date`
    FROM Activity
    GROUP BY player_id
) AS C 
ON (A.player_id = C.player_id AND A.event_date = C.DATE)
```
接着再left join表activity ，排除掉首次登录后第二天没有登录的行。这里用left join，并投影处字段A.player_id和B.player_id。部分B.player_id 为NULL， 表示首次登录后第二天没有登录。
```
SELECT DISTINCT A.player_id AS id1,B.player_id AS id2
FROM Activity AS A
JOIN (
    SELECT player_id, MIN(event_date) AS `date`
    FROM Activity
    GROUP BY player_id
    ) AS C 
    ON (A.player_id = C.player_id AND A.event_date = C.DATE)
LEFT JOIN Activity AS B 
    ON (A.player_id = B.player_id AND DATEDIFF(B.event_date,A.event_date)=1)
```
基于这样的结果，计算比例：
```
SELECT ROUND(SUM(IF(id2 IS NOT NULL,1,0)) / COUNT(DISTINCT id1),2) AS `fraction`
FROM (
    SELECT DISTINCT A.player_id AS id1,B.player_id AS id2
    FROM Activity AS A
    JOIN (
        SELECT player_id, MIN(event_date) AS `date`
        FROM Activity
        GROUP BY player_id
        ) AS C 
        ON (A.player_id = C.player_id AND A.event_date = C.DATE)
    LEFT JOIN Activity AS B 
        ON (A.player_id = B.player_id AND DATEDIFF(B.event_date,A.event_date)=1)
) AS D
```
# 解法二
先求出首次登录后第二天又登录的人数。

首次登录日期：
```
			SELECT MIN(event_date)
			FROM Activity
			WHERE player_id = xxxx
```
表activity自连接，排除掉日期不是首次登录日的行。并统计人数。
```
		SELECT COUNT(DISTINCT A.player_id)
		FROM Activity AS A
		JOIN Activity AS B ON A.player_id = B.player_id AND DATEDIFF(B.event_date,A.event_date)=1
		WHERE A.event_date = (
			SELECT MIN(event_date)
			FROM Activity
			WHERE player_id = A.player_id
		)
```
总人数更明显：
```
		SELECT COUNT(DISTINCT player_id)
		FROM Activity
```
两者相除：
```
SELECT ROUND(
	(
		SELECT COUNT(DISTINCT A.player_id)
		FROM Activity AS A
		JOIN Activity AS B ON A.player_id = B.player_id AND DATEDIFF(B.event_date,A.event_date)=1
		WHERE A.event_date = (
			SELECT MIN(event_date)
			FROM Activity
			WHERE player_id = A.player_id
		)
	)
	/
	(
		SELECT COUNT(DISTINCT player_id)
		FROM Activity
	)
	,
	2
) AS `fraction`
```