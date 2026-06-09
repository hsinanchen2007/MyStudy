寻找只在春季销售的产品等价于（不存在 在春季之外销售的产品），上述转换即把ALL(BETWEEN Spring)改为NOT EXISTS(NOT BETWEEN Spring)。
需要注意的是，关联Product表和Sales表时，关联条件`S.product_id = P.product_id`不能改变。

```
SELECT P.product_id AS product_id, P.product_name AS product_name
FROM Product P
WHERE NOT EXISTS 
    (SELECT *
    FROM Sales S
    WHERE S.product_id = P.product_id AND S.sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31' );
```
理论上NOT EXISTS会比NOT IN快一些（但实际上却慢了一些）。
