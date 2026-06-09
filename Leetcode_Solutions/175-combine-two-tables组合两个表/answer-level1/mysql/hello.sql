### 解题思路
Person左连接Address

### 代码

```mysql
# Write your MySQL query statement below
select p.FirstName, p.LastName,a.City, a.State from Person as p left join Address as a on p.PersonId = a.PersonId;


```