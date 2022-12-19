### 解题思路
1.选出那些不存在order订单customerid那些id就表示从不订购的客户。

### 代码

```mysql
# Write your MySQL query statement below

SELECT customers.Name AS 'Customers'
FROM customers
WHERE customers.id not in
(
SELECT CustomerId from orders
);
```