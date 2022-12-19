### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select a.Name
from Employee a inner join Employee b
on a.Id = b.ManagerId
group by a.Id
having count(*)>=5
```