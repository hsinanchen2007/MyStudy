选取In S8 Not In iPhone
```SQL
SELECT DISTINCT Sales.buyer_id
FROM Sales JOIN Product
ON Sales.product_id = Product.product_id
WHERE Product.product_name = "S8"
AND (Sales.buyer_id NOT IN
(
SELECT Sales.buyer_id
FROM Sales JOIN Product
ON Sales.product_id = Product.product_id
WHERE Product.product_name = "iPhone")
);
```

用SUM值来筛选
```SQL
SELECT DISTINCT buyer_id
FROM Sales JOIN Product
ON Sales.product_id = Product.product_id
GROUP BY buyer_id
HAVING SUM(product_name = "S8") > 0
AND SUM(product_name = "iPhone") = 0;
```