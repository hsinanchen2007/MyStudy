### 解题思路
题目要求地址可以为null,所以用了一个左连接，连接的地方是Personid.
### 代码

```mysql
# Write your MySQL query statement below
select FirstName,Lastname,city,State from Person left join Address on Person.PersonId = Address.PersonId;
```