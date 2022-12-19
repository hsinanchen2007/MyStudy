select p.FirstName, p.LastName, a.City, a.State
from Person p,Address a
where p.personid=a.personid(+);