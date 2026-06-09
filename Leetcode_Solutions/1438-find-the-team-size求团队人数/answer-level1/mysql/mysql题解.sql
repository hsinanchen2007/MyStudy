select E1.employee_id,(select count(employee_id) from Employee where E1.team_id=team_id) team_size
from Employee E1