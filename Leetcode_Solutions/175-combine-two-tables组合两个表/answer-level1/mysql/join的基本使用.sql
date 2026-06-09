### 解题思路
1、首先确定使用左连接
2、使用on不用where

### 代码

```mysql
# Write your MySQL query statement below
select p.FirstName,p.LastName,a.City,a.State from Person p left join Address a on p.PersonId=a.PersonId
```