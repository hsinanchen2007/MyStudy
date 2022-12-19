### 解题思路
可以用 id not in 或者 left join where id is null

### 代码

```mysql
# Write your MySQL query statement below



select c.Name as Customers

from Customers c 
where c.id not in(
    select CustomerId from orders

);



select  c.Name as Customers

from Customers c 
left join orders o on o.CustomerId=c.id
where o.id is null
```