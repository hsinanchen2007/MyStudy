考点：join、left join、right join、inner join的区别。mysql的join 默认是inner join
```
select FirstName, LastName, City, State from Person p left join Address a on p.PersonId = a.PersonId
```
