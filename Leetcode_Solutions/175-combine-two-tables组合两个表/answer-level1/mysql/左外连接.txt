### 解题思路
此处撰写解题思路
左外连接：保留左边的悬浮数组
### 代码

```mysql
# Write your MySQL query statement below
Select FirstName, LastName, City, State
From  Person left join Address
on Address.PersonId = Person.PersonId
```