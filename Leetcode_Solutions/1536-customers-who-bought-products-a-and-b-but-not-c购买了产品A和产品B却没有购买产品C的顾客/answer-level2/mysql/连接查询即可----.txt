### 解题思路
1.连接自身

### 代码

```mysql
# Write your MySQL query statement below



select o.customer_id,c.customer_name
from Orders o
left join Orders o1
on o.customer_id=o1.customer_id
left join Customers c
on c.customer_id=o.customer_id
where o.product_name='A' and o1.product_name='B'
and not exists(select customer_id from Orders o2 where o2.customer_id=o.customer_id and 
o2.product_name='C')
```