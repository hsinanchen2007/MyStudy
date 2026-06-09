SELECT product_name,unit
FROM Products
JOIN (SELECT product_id,SUM(unit) AS unit
      FROM Orders
      WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29'
      GROUP BY product_id
      HAVING SUM(unit) >= 100) AS A
ON Products.product_id = A.product_id