select FirstName, LastName, City, State from Person
left join Address on Person.PersonId = Address.PersonId

关联后，产生临时表，临时表展示全部数据，然后再根据where条件过滤

left join 左连接 左边的表数据完整展示，右边的表数据根据条件展示，有则显示，没有则为null
right join 右连接 右边的表数据完整展示，左边的表数据根据条件展示，有则显示，没有则为null