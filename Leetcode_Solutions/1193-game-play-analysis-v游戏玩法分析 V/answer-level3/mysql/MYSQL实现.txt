左连接俩次，第一次on为日期小于主表日期，并且player_id相同，这一步为了筛选出所有用户第一次登陆的日期
接着再左连接一次，on为主表日期+1，并且player_id相同。
此时如果第二张表的日期为NULL，则剩下的记录是每个用户第一次登陆的数据以及第三张表中每个用户第二天是否登陆的信息。

```
SELECT
a1.event_date as install_dt,
COUNT(a1.player_id) as installs,
ROUND(COUNT(a3.player_id)/COUNT(a1.player_id),2) as Day1_retention
FROM
	activity a1
	LEFT JOIN activity a2 ON a1.event_date > a2.event_date 
	AND a1.player_id = a2.player_id LEFT JOIN activity a3 ON a1.player_id=a3.player_id AND DATEDIFF(a1.event_date, a3.event_date)=-1
WHERE a2.event_date IS NULL
GROUP BY a1.event_date
```
