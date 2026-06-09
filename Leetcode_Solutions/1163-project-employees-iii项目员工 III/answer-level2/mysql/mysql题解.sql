select M.project_id,M.employee_id
from 
(
    select P.project_id,P.employee_id,
    RANK() over(partition by P.project_id order by E.experience_years desc) as ranking
    from Project P,Employee E
    where P.employee_id=E.employee_id
)M
where M.ranking<=1