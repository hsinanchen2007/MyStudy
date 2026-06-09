主要是想用开窗来解决，目的是为了练习练习mysql的变量使用，感觉挺不错的，效率还行，下面是我的思路
1. 按用户id和event_date进行分组，目的是为了求出这个用户第一次的登录和第二次的登录（rank排序）
2. 通过rank排序我们取到了用户第一次登录和第二次登录的数据，接着按照用户分组，目的是看该用户的第二次登录是否和第一次登录相隔一天
3. 当我们知道用户第二次登录的情况之后，最后再分组计算最终的结果即可
```
SELECT event_date AS install_dt, COUNT(*) AS installs
	, round(SUM(isCalc) / COUNT(*), 2) AS Day1_retention
FROM (
	SELECT a.player_id, MIN(a.event_date) AS event_date, MAX(CASE 
			WHEN a.rk = 2
			AND DATE_ADD(lastDate, INTERVAL 1 DAY) = event_date THEN 1
			ELSE 0
		END) AS isCalc
	FROM (
		SELECT a.player_id, a.event_date, a.lastDate, a.rk
		FROM (
			SELECT a.player_id, a.event_date, @preDate AS lastDate
				, CASE 
					WHEN @prePid = a.player_id THEN @curRank := @curRank + 1
					ELSE @curRank := 1
				END AS rk, @prePid := player_id, @preDate := event_date
			FROM Activity a, (
					SELECT @curRank := 0, @prePid := NULL
						, @preDate := NULL
				) r
			ORDER BY a.player_id, a.event_date
		) a
		WHERE a.rk = 1
			OR a.rk = 2
	) a
	GROUP BY a.player_id
) a
GROUP BY a.event_date
```
