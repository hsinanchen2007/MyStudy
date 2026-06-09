select E1.Name
from Employee E1,Employee E2
where E1.Id=E2.ManagerId
group by E2.ManagerId
having count(distinct E2.Id)>=5