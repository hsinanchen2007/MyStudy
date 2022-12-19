### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select p.firstname,p.lastname,a.city,a.state
from person p
left join address a
on p.personid=a.personid
```