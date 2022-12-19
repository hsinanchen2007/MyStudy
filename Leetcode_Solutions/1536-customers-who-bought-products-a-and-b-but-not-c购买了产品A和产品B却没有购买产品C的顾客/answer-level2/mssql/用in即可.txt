### 解题思路
此处撰写解题思路

### 代码

```mssql
/* Write your T-SQL query statement below */
select * from Customers c
where customer_id in
(select customer_id from Orders where product_name = 'A')
and customer_id in
(select customer_id from Orders where product_name = 'B')
and customer_id not in
(select customer_id from Orders where product_name = 'C')
```