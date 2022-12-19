select a.employee_id, count(b.employee_id) as team_size from
employee a inner join employee b
on a.team_id=b.team_id
group by a.employee_id,a.team_id