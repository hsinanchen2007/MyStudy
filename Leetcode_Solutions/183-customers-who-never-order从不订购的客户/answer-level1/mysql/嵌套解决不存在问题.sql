### 解题思路
嵌套解决不存在问题

### 代码

```mysql
# Write your MySQL query statement below
SELECT a.Name AS 'Customers'
FROM Customers AS a
WHERE NOT EXISTS
    (
        SELECT *
        FROM Orders AS b
        WHERE b.CustomerId = a.Id
    )
```