一看到题，就想到`左连接`去掉`null`值的方式：

````
SELECT c.Name AS Customers
FROM dbo.Customers AS c
    LEFT JOIN dbo.Orders AS o
        ON c.Id = o.CustomerId
WHERE o.Id IS NULL;
````

或者使用` not in  `或者` not exists`
````
SELECT c.Name AS Customers
FROM dbo.Customers AS c
WHERE NOT EXISTS
(
    SELECT CustomerId FROM dbo.Orders WHERE c.Id = CustomerId
);
````