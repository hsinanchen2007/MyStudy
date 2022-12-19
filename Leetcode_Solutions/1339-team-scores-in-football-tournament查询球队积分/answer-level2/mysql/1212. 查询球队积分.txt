1.先用union all来合并两张表，对换host_goals 和guest_goals
2.case根据分数不同返回不同值

union 和 union all 区别？
union压缩了重复数据， union all不压缩

```
select team_id, team_name,sum(
case 
    when host_goals > guest_goals then 3
    when host_goals = guest_goals then 1
    else 0
end
)  as num_points
from
(
    select * from 
    Matches
    union all
    (
        select  match_id,
                guest_team as host_team,
                host_team as guest_team,
                guest_goals as host_goals,
                host_goals as guest_goals
        from 
            Matches
    )
) temp
right join 
Teams
on 
Teams.team_id = temp.host_team
group by team_id
order by num_points desc, team_id asc

```
