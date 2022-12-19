oracle可以使用outer join的方法
select p.FirstName, p.LastName, a.City, a.State from Person p , Address a where p.PersonId = a.PersonId(+);
 +号一定要放在列数少的那个表