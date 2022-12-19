select P.project_id project_id,
Round(sum(E.experience_years)/count(E.employee_id ),2) average_years
from Project P,Employee E
where P.employee_id=E.employee_id
group by P.project_id