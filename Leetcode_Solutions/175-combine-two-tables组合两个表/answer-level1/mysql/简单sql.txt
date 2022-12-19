### 解题思路
person必须有不管地址有没有 那就是左连接  

### 代码

```mysql
# Write your MySQL query statement below

select t.FirstName,t.LastName,u.City,u.State from Person t left join Address u on t.PersonId=u.PersonId;
```