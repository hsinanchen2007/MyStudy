### 解题思路
本质是考察内外连接的意思

### 代码

```mysql
select FirstName, LastName, City,State from Address a right join Person p on p.PersonId =a.PersonId
```
