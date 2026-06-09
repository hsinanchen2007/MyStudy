mysql
```SQL
SELECT ROUND(COUNT(t.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity),2) AS fraction  
FROM (
    SELECT DISTINCT player_id, MIN(event_date) AS first_date
    FROM Activity 
    GROUP BY player_id
) AS t, Activity a
WHERE t.player_id=a.player_id AND DATEDIFF(a.event_date,t.first_date)=1
```
思考过程：
- 先找出玩家的第一次登录时间
- 然后然后找出接着第二天就登录的玩家`WHERE t.player_id=a.player_id AND DATEDIFF(a.event_date,t.first_date)=1`
- 最后计算比例
- 小数点保留用`ROUND(算式/数值，保留小数点位数)`