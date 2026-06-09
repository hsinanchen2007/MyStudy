### 解题思路
首先要抓住需求，不管是否提供address都要把这个成员的信息打印出来，所以我们使用左外连接就可以啦

### 代码

```mysql
# Write your MySQL query statement below
select FirstName,LastName,City,State from Person left join Address on Person.PersonId = Address.PersonId; 
```