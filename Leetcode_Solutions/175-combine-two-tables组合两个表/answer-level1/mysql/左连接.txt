### 解题思路
此处撰写解题思路
此题运用到了左连接
### 代码

```mysql
# Write your MySQL query statement below
select  p.FirstName, p.LastName, a.City, a.State from Person p left join Address a on p.PersonId = a.PersonId;
```