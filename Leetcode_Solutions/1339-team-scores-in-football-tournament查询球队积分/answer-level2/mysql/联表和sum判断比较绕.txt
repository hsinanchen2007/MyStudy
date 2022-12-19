### 解题思路
sum里面的case比较难处理 其他的都好说
### 代码

```mysql
# Write your MySQL query statement below

select t.team_id,t.team_name,sum(case when 
t.team_id = m1.host_team and m1.host_goals > m1.guest_goals then 3 when m1.host_goals = m1.guest_goals then 1 when  t.team_id = m1.guest_team and m1.guest_goals>m1.host_goals THEN 3 ELSE 0 END ) `num_points` from Teams t left join Matches m1 on t.team_id = m1.host_team or t.team_id = m1.guest_team group by t.team_id order by num_points desc,team_id asc
```