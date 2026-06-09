select employee_id, t1.team_size from Employee left join
(select team_id,count(team_id) as team_size from Employee
group by team_id) as t1 on Employee.team_id=t1.team_id


