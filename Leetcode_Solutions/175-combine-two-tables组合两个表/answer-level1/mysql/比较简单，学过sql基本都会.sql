### 解题思路
没得别的 就是多表查询

### 代码

```mysql
# Write your MySQL query statement below
select p.FirstName,p.LastName,a.City,a.State from Person p left join Address a on p.personId = a.personId
```