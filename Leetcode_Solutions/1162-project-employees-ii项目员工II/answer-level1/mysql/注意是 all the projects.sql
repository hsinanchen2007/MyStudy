select project_id from Project
group by project_id
having count(distinct employee_id) = 
(select count(distinct employee_id) from Project group by project_id order by count(distinct employee_id) desc limit 1);