//最简单的一道题
select p1.FirstName,p1.LastName,a1.City,a1.State 
from Person p1
left join AddressId a1 
on p1.PersonId = a1.PersonId