### 解题思路
此处撰写解题思路

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select FirstName,LastName,City,State from Person  p left join Address a on p.PersonId=a.PersonId
```
/*
Oracle同其他数据库一样，有outter和inner join，Person表是主表，所以用left join来查询出Person所有数据

*/