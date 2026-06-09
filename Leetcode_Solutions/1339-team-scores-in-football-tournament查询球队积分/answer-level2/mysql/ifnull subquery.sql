### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select t.team_id, t.team_name, ifnull(total_count,0) as num_points 
from Teams t 
left join 
(select host_team, sum(host_points) as total_count
from 
((select host_team, case 
when host_goals> guest_goals then 3
when host_goals=guest_goals then 1
else 0 
end as host_points from Matches)
union all
(select guest_team as host_name, case 
when host_goals<guest_goals then 3 
when host_goals=guest_goals then 1
else 0
end as host_points from Matches)) temp_1
group by host_team) temp
on t.team_id=temp.host_team 
order by num_points desc, team_id asc 



```