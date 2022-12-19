```
/* Write your PL/SQL query statement below */

select distinct team_id,team_name,
        sum(case when team_id in (host_team,guest_team) and team_id=state then 3 
                when team_id in (host_team,guest_team) and state=0 then 1 else 0 end)
                over(partition by team_id) num_points 
from (
    select team_id,team_name,match_id,(case when host_goals>guest_goals  then host_team
                    when host_goals<guest_goals  then guest_team
                    else 0 end ) state,host_team,guest_team
    from matches,teams
)
order by num_points desc,team_id;
```
最内层的子查询获胜队的编号,如果平局,返回0;
计算得分:因为有队没参加比赛,但是统计结果时还得出现,所以使用全连接,但需要筛选出参加比赛的队伍(通过team_id in (host_team,guest_team)),然后依据内层的查询结果求和即可.