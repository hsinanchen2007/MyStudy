### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement belo
select p.FirstName,p.LastName,a.City,a.State from Person p left join Address a on a.PersonId = p.PersonId
```
无论怎么样都要有Person的信息。左连接