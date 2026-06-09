### 解题思路
主要考察点在left join，因为直接用join默认inner join会filter掉地址为空的元祖
另外犯了一个低级错误是一直把on写成了where.......

### 代码

```mysql
select FirstName, LastName, City, State
from Person
left join Address
on Person.PersonId = Address.PersonId
```