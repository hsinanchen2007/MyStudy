### 解题思路
此处撰写解题思路
left join oracle最常用的多表关联查询
### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select t.FirstName, t.LastName, n.City, n.State
from Person t left join Address n
on t.PersonId = n.PersonId
```