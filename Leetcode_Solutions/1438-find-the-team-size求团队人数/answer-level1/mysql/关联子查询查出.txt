子查询先基于员工COUNT各TEAM的数量
然后基于TEAMID 关联员工进行查询

select 
e.employee_id, 
t.team_size 
from Employee e 
join (
select team_id,count(1) as team_size  from Employee group by 1
) t on (e.team_id = t.team_id)
