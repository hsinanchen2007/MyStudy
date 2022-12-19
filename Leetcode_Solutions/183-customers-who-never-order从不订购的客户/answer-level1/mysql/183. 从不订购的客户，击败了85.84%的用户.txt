### 解题思路

首先将两个表以 customers.id=orders.customerid 左连接，这样就出现一个新表，其中这个新表中 customerid 有 NULL 值，以此为条件，选出含有 NULL 的记录，就是从不订购任何东西的客户。

执行用时 : 187 ms, 在所有 MySQL 提交中击败了85.84%的用户

希望还有更好的方法。

### 代码

```mysql
# Write your MySQL query statement below
select a.name Customers from customers a left join orders b on a.id=b.customerid where b.customerid is null
```