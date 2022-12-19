select ifnull(E2.unique_id,null) unique_id,E1.name name
from Employees E1 left join EmployeeUNI E2
on E1.id=E2.id