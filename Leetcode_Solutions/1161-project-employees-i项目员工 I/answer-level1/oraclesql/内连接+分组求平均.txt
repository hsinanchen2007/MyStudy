法一：
select p.project_id,
       round(sum(e.experience_years) / count(e.employee_id), 2) as average_years
  from Project p
 inner join Employee e
    on p.employee_id = e.employee_id
 group by p.project_id;

法二：
select p.project_id, round(avg(e.experience_years), 2) as average_years
  from Project p
 inner join Employee e
    on p.employee_id = e.employee_id
 group by p.project_id;