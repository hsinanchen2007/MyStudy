### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
SELECT 
    c.name AS Customers 
FROM 
    Customers c
WHERE 
    c.id not in(
        SELECT 
            o.CustomerId 
        FROM 
            orders o )

```