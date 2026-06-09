```mysql []
SELECT p.product_name,SUM(o.unit) unit 
FROM Products p JOIN Orders o
ON p.product_id=o.product_id 
WHERE (O.order_date between '2020-02-01' AND '2020-02-29')
GROUP BY p.product_name
HAVING unit>=100
ORDER BY unit DESC;
```

