一开始采用
select Person.FirstName, Person.LastName, Address.City, Address.State **from Person, Address where** Address.PersonId = Person.PersonId
语句进行查询；
此语句在地址表无PersonId的情况下；将无法进行查询。本应返回null,null;但是实际结果为空。
在经过仔细阅读题目后，改用
select Person.FirstName, Person.LastName, Address.City, Address.State **from Person left join Address on** Address.PersonId = Person.PersonId
使用左连接后，保证了Person表的数据被查询出来的同时，可查询到Address表的内容为null。

