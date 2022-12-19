**1. 在Activity表的右边增加一列每个玩家的MIN(event_date)，即每个玩家的安装日期**
```
SELECT a.*, 
       (SELECT MIN(event_date)
        FROM Activity
        WHERE player_id = a.player_id) install_dt
FROM Activity a
```
**2. 按install_dt分组，查询出每个安装日期install_dt、当天安装游戏的玩家数量installs**
```
SELECT install_dt, COUNT(DISTINCT player_id) installs
FROM
    (SELECT a.*, 
            (SELECT MIN(event_date)
             FROM Activity
             WHERE player_id = a.player_id) install_dt
     FROM Activity a) need
GROUP BY install_dt
```
**3. 再查询第一天的保留时间Day1_retention**
日期X的保留时间等于安装日期为X且第二天登陆了的玩家数量，除以安装日期为X的玩家数量，
- 安装日期为X且第二天登陆了的玩家数量：
`COUNT(DISTINCT IF(event_date = install_dt + 1, player_id, NULL)`
  这里`event_date = install_dt + 1`表示第二天登陆了的玩家，`DISTINCT`是为了防止有的玩家第二天登陆两次；
- 安装日期为X的玩家数量（即为installs）：
`COUNT(DISTINCT player_id)`
- 所以日期X的保留时间：
`COUNT(DISTINCT IF(event_date = install_dt + 1, player_id, NULL)) / 
 COUNT(DISTINCT player_id)`
- 再保留两位小数即可：
`ROUND(COUNT(DISTINCT IF(event_date = install_dt + 1, player_id, NULL)) / 
       COUNT(DISTINCT player_id), 2)`

**4. 最终代码**
```
SELECT install_dt, COUNT(DISTINCT player_id) installs, 
       ROUND(COUNT(DISTINCT IF(event_date = install_dt + 1, player_id, NULL)) / 
       COUNT(DISTINCT player_id), 2) Day1_retention
FROM
    (SELECT a.*, 
            (SELECT MIN(event_date)
             FROM Activity
             WHERE player_id = a.player_id) install_dt
     FROM Activity a) need
GROUP BY install_dt
```
思路很简单，但是运行起来好像有点慢


