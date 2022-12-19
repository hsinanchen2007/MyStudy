### 解题思路
此处撰写解题思路
分别算出客队跟主队的分数然后union  注意这里需要union all
### 代码

```mysql
# Write your MySQL query statement below

select a.team_id as team_id,a.team_name as team_name,ifnull(b.num_points,0) as num_points    
from Teams a left join 
(
    select res.team_id as team_id,res.team_name as team_name,sum(res.num_points) as num_points 
    from
    (
        select t.team_id,t.team_name,sum(case when host_goals  > guest_goals  then 3 when host_goals  < guest_goals  then 0 else 1 end) as num_points  
        from Teams t inner join Matches m on t.team_id = m.host_team   group by t.team_id

        union all

        select t.team_id,t.team_name,sum(case when host_goals  < guest_goals  then 3 when host_goals  > guest_goals  then 0 else 1 end) as num_points  
        from Teams t inner join Matches m on t.team_id = m.guest_team  group by t.team_id
    ) res
    group by res.team_id
)b
on a.team_id =b.team_id   
order by num_points desc,team_id






















```