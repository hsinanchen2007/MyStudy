
1. 找出所有玩家的首次登陆时间
```
SELECT player_id, MIN(event_date)
FROM Activity
GROUP BY player_id
```
这里也要找出player_id，不然可能求出其他玩家在这个玩家首次登录那天的数据。

2. 计算出从首次登录日期开始至少连续两天登录的玩家的数量
  （连续出现N次类型题目参考180.连续出现的数字，
   datediff()函数参考题目197.上升的温度）
```
SELECT COUNT(DISTINCT a1.player_id)
FROM Activity AS a1, Activity AS a2
WHERE a1.player_id = a2.player_id
    AND DATEDIFF(a1.event_date, a2.event_date) = -1
    AND (a1.player_id, a1.event_date) IN
        (SELECT player_id, MIN(event_date)
        FROM Activity
        GROUP BY player_id)
```

3. 计算所有玩家数量
```
SELECT COUNT(DISTINCT player_id) FROM Activity
```
这里不能用MAX(player_id)，因为有的玩家可能没登陆，比如说有id为1,2,3的玩家，id=2的玩家没登陆，总玩家只有2个。

4.  从首次登录日期开始至少连续两天登录的玩家的数量/所有玩家，保留两位小数ROUND()
```
SELECT ROUND(COUNT(DISTINCT a1.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM Activity AS a1, Activity AS a2
WHERE a1.player_id = a2.player_id
    AND DATEDIFF(a1.event_date, a2.event_date) = -1
    AND (a1.player_id, a1.event_date) IN
        (SELECT player_id, MIN(event_date)
        FROM Activity
        GROUP BY player_id)
```
