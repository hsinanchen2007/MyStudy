别名有助于提高运算效率

SELECT DISTINCT S1.product_id,P1.product_name
FROM Sales S1 JOIN  Product P1
ON S1.product_id = P1.product_id
WHERE sale_date  BETWEEN '2019-01-01' AND '2019-03-31'
AND S1.product_id NOT IN
(SELECT S.product_id
FROM Sales S
WHERE S.sale_date  NOT BETWEEN '2019-01-01' AND '2019-03-31');