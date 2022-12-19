### 解题思路
此处撰写解题思路

### 代码
#解法1 字查处 subquery
```mysql
# Write your MySQL query statement below
select c.name Customers
from Customers c
where c.id not in
(select CustomerId
from Orders)

解法2 多表链接 left join

select c.name Customers
from Customers c left join Orders o
on c.id=o.CustomerId
where o.CustomerId is null

```