select p.FirstName,p.LastName,a.City,a.State
from person p left join in Address a 
on p.PersonId = a.personId;
或者这种写法
select p.FirstName,p.LastName,a.City,a.State
from person p ， Address a 
where p.PersonId = a.personId(+);