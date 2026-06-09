### 解题思路
这一题主要考察 left join 的用法

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select FirstName,LastName,City,state
from Person left join Address
on Person.PersonID = Address.PersonID
```