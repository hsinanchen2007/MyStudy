```mysql
SELECT
	p.product_id,p.product_name
FROM
	Sales s,Product p
WHERE
	s.product_id = p.product_id
GROUP BY
	s.product_id
HAVING
	SUM(s.sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31') = 0
```
