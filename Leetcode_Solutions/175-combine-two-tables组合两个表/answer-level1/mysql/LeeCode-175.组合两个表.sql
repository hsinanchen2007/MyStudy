#使用别名
#使用左连接查询
select p.FirstName,p.LastName,p.City,p.State
from Person p
left join Adrress
on p.PersonId=a.PerssonId;