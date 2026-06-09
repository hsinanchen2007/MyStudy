### 解题思路
两个表相连，要取出相同的数据：
外部连接（outer join）和自联结（inner join）
（1）外部链接分为：left join和right join
left join:是先取出person表中的数据后匹配address表中的数据
right join：先取出address表中的数据后匹配person表中的数据
（2）自联结：inner join并不以谁为基础,它只显示符合条件的记录
综上可知，“满足条件：无论 person 是否有地址信息，都需要基于上述两表提供 person 的以下信息”
选择左连接
### 代码

```mysql
# Write your MySQL query statement below
Select FirstName, LastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId
```