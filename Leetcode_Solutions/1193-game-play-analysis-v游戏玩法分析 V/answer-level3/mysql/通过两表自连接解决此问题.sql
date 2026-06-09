```
SELECT a1.install_dt,COUNT(a1.player_id) AS installs,round(COUNT(a2.player_id)/COUNT(a1.player_id),2) AS Day1_retention
FROM 
(
	SELECT player_id,MIN(event_date) AS install_dt
	FROM Activity
	GROUP BY player_id
) AS a1
left JOIN Activity AS a2
	ON (a2.event_date = DATE_ADD(a1.install_dt,INTERVAL 1 DAY) AND a2.player_id = a1.player_id)
GROUP BY a1.install_dt
```

原老哥的解法：这里略加修改

解法一

先找到每个玩家的安装日期。 安装日期 定义为 每个玩家 第一次登录的日期。

对玩家分组，求每组最小的日期，即为登录日期。

结果命名为表A。

(
	SELECT player_id,MIN(event_date) AS `install_date`
	FROM Activity
	GROUP BY player_id
) AS A

依次统计安装日期的总人数和安装日期第二天的总人数。

连接表A和活动表，再按登录日期分组，统计每组的总人数，以及第二天的总人数。

注意：因存在玩家第二天没有登录，需用left join。连接条件同一个玩家第二天又登录。

作者：jason-2
链接：https://leetcode-cn.com/problems/game-play-analysis-v/solution/liang-chong-jie-fa-by-jason-2-7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。