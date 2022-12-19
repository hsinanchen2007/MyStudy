select id id,name name
from Students
where department_id not in (select id from Departments)