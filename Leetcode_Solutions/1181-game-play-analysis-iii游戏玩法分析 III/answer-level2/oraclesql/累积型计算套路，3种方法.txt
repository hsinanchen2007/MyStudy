
#累积型计算套路
#方法1：计算型子查询
/*
select player_id,event_date,(select sum(games_played) from Activity a2 where a2.player_id=a1.player_id and a2.event_date<=a1.event_date) games_played_so_far
from Activity a1
group by player_id,event_date（分组可以不加，但是最好加上，否则容易出现重复记录）
*/
#方法2：自连接
select a1.player_id,a1.event_date,sum(a2.games_played) games_played_so_far
from Activity a1,Activity a2
where
a1.player_id=a2.player_id
and a2.event_date<=a1.event_date
group by a1.player_id,a1.event_date

#窗口函数 mysql8.0以上（oracle）
select player_id ,to_char(event_date,'yyyy-MM-dd')  event_date,
sum(games_played) over(partition by player_id order by event_date asc rows between unbounded preceding and current row)games_played_so_far
from Activity