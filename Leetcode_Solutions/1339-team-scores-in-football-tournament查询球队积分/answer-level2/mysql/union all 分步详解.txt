思路：
1. (表1) 计算host_team的每场比赛得分，再计算每个host_team的总得分(group by)

```
(select host_team,
sum(case 
    when host_goals>guest_goals then 3 
    when host_goals=guest_goals then 1 
    else 0
end) host_points
from Matches
group by host_team
```

2. (表2) 计算guest_team的每场比赛得分，再计算每个guest_team的总得分(group by)

```
select guest_team,
sum(case 
    when host_goals<guest_goals then 3 
    when host_goals=guest_goals then 1
    else 0
end) guest_points
from Matches
group by guest_team
```
3. 两表合一形成一个包含全部team_name, points的表 （union all)

```
(select host_team,
sum(case 
    when host_goals>guest_goals then 3 
    when host_goals=guest_goals then 1 
    else 0
end) host_points
from Matches
group by host_team)
union all 
(select guest_team,
sum(case 
    when host_goals<guest_goals then 3 
    when host_goals=guest_goals then 1
    else 0
end) guest_points
from Matches
group by guest_team)
```
4. 最后输出需要有team_name，Teams与第三步形成的表格left join

```
from Teams t left join 
((select host_team,
sum(case 
    when host_goals>guest_goals then 3 
    when host_goals=guest_goals then 1 
    else 0
end) host_points
from Matches
group by host_team)
union all 
(select guest_team,
sum(case 
    when host_goals<guest_goals then 3 
    when host_goals=guest_goals then 1
    else 0
end) guest_points
from Matches
group by guest_team)) a
on t.team_id=a.host_team
```

5. 最后计算的是每个team的总分，而每个队伍在比赛中有可能是host_team或者guest_team，所以我们需要按照team_name进行group by。用select选出需要的队名、ID并对分数进行求和。
```
select team_id,team_name
,sum(ifnull(host_points,0)) num_points
from Teams t left join 
((select host_team,
sum(case 
    when host_goals>guest_goals then 3 
    when host_goals=guest_goals then 1 
    else 0
end) host_points
from Matches
group by host_team)
union all 
(select guest_team,
sum(case 
    when host_goals<guest_goals then 3 
    when host_goals=guest_goals then 1
    else 0
end) guest_points
from Matches
group by guest_team)) a
on t.team_id=a.host_team
group by t.team_id, t.team_name
order by num_points DESC, team_id ASC
```