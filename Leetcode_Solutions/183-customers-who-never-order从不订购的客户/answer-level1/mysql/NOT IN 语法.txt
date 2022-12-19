```
NOT IN

mysql> select 5 not in (1,2,3,4,5);
+----------------------+
| 5 not in (1,2,3,4,5) |
+----------------------+
|                    0 |
+----------------------+

IN

mysql> select 5 in (1,2,3,4,5);
+------------------+
| 5 in (1,2,3,4,5) |
+------------------+
|                1 |
+------------------+
```


```
# Write your MySQL query statement below
SELECT 
Name AS Customers 

FROM Customers 

WHERE Id NOT IN (
                SELECT CustomerId 
                FROM Orders #表名
                GROUP BY CustomerId
                );
```
