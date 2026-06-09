### 解题思路
考点内容主要时数据库中的左连接和右连接的区别。

### 代码

```mysql
# Write your MySQL query statement below
select Person.FirstName,Person.LastName,Address.City,Address.State from Person left join Address on Person.PersonId=Address.PersonId ;
```