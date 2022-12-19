先找出每个用户第一次登陆的记录作为主表，左连接activity，on 天数差是+1，如果附表为null则不是连续登录

```
SELECT
	ROUND((SELECT
		count(tmp.player_id)
	FROM
		( SELECT activity.player_id, min( event_date ) AS event_date FROM activity GROUP BY activity.player_id ) AS tmp
		LEFT JOIN activity ON DATEDIFF( activity.event_date, tmp.event_date ) = 1 AND tmp.player_id= activity.player_id
	WHERE
		activity.player_id IS NOT NULL )/
		(SELECT
		count(tmp.player_id)
	FROM
		( SELECT activity.player_id, min( event_date ) AS event_date FROM activity GROUP BY activity.player_id ) AS tmp
		LEFT JOIN activity ON DATEDIFF( activity.event_date, tmp.event_date ) = 1 AND tmp.player_id= activity.player_id ),2) as fraction

```
