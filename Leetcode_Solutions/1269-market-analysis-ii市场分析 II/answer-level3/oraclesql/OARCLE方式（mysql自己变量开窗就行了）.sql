#sql题一致是这种，待优化吧
```
/* Write your PL/SQL query statement below */
SELECT a.user_id AS seller_id
	, CASE 
		WHEN a.favorite_brand = b.item_brand THEN 'yes'
		ELSE 'no'
	END AS "2nd_item_fav_brand"
FROM (
	SELECT a.user_id, a.favorite_brand, b.item_id
	FROM Users a
		LEFT JOIN (
			SELECT item_id, seller_id
			FROM (
				SELECT order_date, item_id, seller_id, row_number() OVER (PARTITION BY seller_id ORDER BY order_date) AS rk
				FROM Orders
			) a
			WHERE a.rk = 2
		) b
		ON a.user_id = b.seller_id
) a
	LEFT JOIN Items b ON a.item_id = b.item_id
```
