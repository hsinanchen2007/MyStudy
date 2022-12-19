### 解题思路
首先，这是两个表，当Customers 表中的成员订购了东西的话，那么就会在orders表中留下记录。那么我们只需要把所有orders表中的ID 全部排出就行了。。。、
所以会想到用not in 来写。

### 代码

```mysql
SELECT Customers.Name AS Customers
FROM Customers
WHERE Customers.Id NOT IN (
    SELECT CustomerId
    FROM Orders
)


```