1.  #### 首先使用min函数和group by找到所有玩家初次在平台使用设备玩游戏的时间（类似上一题）
```
select player_id,min(event_date) as first_login from Activity group by player_id
```
2.  #### 将步骤1的结果作为子查询，外层再套用一层，查找player_id和device_id即可
```
select a.player_id ,a.device_id from Activity a where (a.player_id ,a.event_date) in 
(select player_id,min(event_date) as first_login from Activity group by player_id)
```
