### 解题思路
左连接忽略右边的表是否存在值
### 代码

```mysql
# Write your MySQL query statement below
select Person.FirstName,Person.LastName,Address.City,Address.State
from
Person left join Address 
on Person.PersonId=Address.PersonId
```