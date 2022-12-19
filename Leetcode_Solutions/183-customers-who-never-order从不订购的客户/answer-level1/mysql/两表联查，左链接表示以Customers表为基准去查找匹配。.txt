### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
SELECT NAME AS
    Customers 
FROM
    customers
    LEFT JOIN orders ON customers.Id = orders.CustomerId 
WHERE
    orders.CustomerId IS NULL
```