```
SELECT customer_id
FROM (SELECT DISTINCT c.customer_id, c.product_key as cpk, p.product_key as ppk FROM customer c LEFT JOIN product p ON c.product_key=p.product_key) tmp
GROUP BY customer_id
HAVING COUNT(cpk) = (SELECT COUNT(product_key) FROM product)
    AND COUNT(ppk) = (SELECT COUNT(product_key) FROM product)
```
