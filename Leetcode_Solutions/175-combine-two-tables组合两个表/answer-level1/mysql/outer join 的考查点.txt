### 解题思路
此处考查的是outer join。 
outer join 会返回两个表中的所有字段。又被分为left join和right join。
left join 只返回左表中已有的数据，而不管右表中是否满足条件的数据; rigth join 反之。

### 代码

```mysql
# Write your MySQL query statement below
select FirstName, LastName, City, State 
  from Person p left join Address a 
  on p.PersonId = a.PersonId;
```