### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select p.FirstName, p.LastName, a.City, a.State
from person p
left join address a
on p.PersonId = a.PersonId
```