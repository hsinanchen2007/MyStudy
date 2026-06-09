### 解题思路
a,b俩表，where俩条件，别忘了distinct
### 代码

```mysql
# Write your MySQL query statement below
select distinct a.Email from Person as a, Person as b where a.Id <> b.Id and a.Email = b.Email
```