类似题 [512. 游戏玩法分析 II](https://leetcode-cn.com/problems/game-play-analysis-ii/solution/san-chong-fang-fa-lian-he-cha-xun-bian-liang-fa-he/) 也是这三种方法。
## MySQL 联合查询
```
SELECT
    a1.player_id,
    a1.event_date,
    SUM(a2.games_played) AS games_played_so_far
FROM 
    Activity AS a1,
    Activity AS a2
WHERE 
    a1.player_id = a2.player_id AND
    a1.event_date >= a2.event_date
GROUP BY a1.player_id, a1.event_date
```
## MySQL 变量法
```
select 
    a.player_id,
    a.event_date,
    case
        when @prev = a.player_id then @cnt := @cnt + a.games_played
        when (@prev := a.player_id) is not null then @cnt := a.games_played
    end games_played_so_far
from 
    Activity a,
    (
        select 
            @cnt := 0,
            @prev := null
    ) t
order by
    a.player_id,
    a.event_date
```
## MSSQL 窗口函数
```
select 
    player_id,
    event_date,
    sum(games_played) over(partition by player_id order by event_date) games_played_so_far
from Activity
```


