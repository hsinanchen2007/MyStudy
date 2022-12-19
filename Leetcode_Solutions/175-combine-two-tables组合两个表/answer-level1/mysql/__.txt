### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select FirstName, LastName, City, State from Person as pp
left  join Address as aa on aa.PersonId=pp.PersonId
```低能问题