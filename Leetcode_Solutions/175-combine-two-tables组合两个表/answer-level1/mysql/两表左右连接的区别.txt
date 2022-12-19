### 解题
考察左连接和右连接的区别；左连接是保持左表的全部存在，右连接是保持右表的全部存在。。。。。。。。。。。。。。。。。。。。。。。。

### 代码

```mysql
select p.FirstName,p.LastName,a.City,a.State from Person p left join Address a on p.PersonId=a.PersonId
```