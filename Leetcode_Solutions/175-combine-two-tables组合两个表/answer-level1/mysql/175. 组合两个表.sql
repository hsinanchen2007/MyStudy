- 左连接 left join

left join Table2
on 条件

```
# Write your MySQL query statement below

# 这是错的
# select Person.FirstName, Person.LastName, Address.City, Address.State
# from Person, Address
# where Person.PersonId = Address.PersonId

# 外连接 基于左表连接右表 left join

select FirstName, LastName, City, State
from Person
left join Address
on Person.PersonId = Address.PersonId
```
