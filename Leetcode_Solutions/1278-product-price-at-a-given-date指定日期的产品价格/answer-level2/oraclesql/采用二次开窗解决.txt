ps：这是我的第一种思路
#第一种思路需要解释一下，
题意：求2019-08-16（包含）之前的商品的最新价格，如果有新商品并不在这个日期之前，那么这个新商品在这个日期时的价格就是10

首先第一次开窗取rk=1 or chage_date<= 2019-08-16的目的就是为了那部分新商品（不需要关心新商品到底更新了几次价格，在2019-08-16之前这个新商品价格就是10）
第二次开窗就是按照日期降序排序，取rk = 1的信息即可（新商品这个时候只有一条记录，rk = 1，第二次开窗无论如何新商品只会有一条记录）
```
/* Write your PL/SQL query statement below */

SELECT product_id
	, CASE 
		WHEN change_date > '2019-08-16' THEN 10
		ELSE new_price
	END AS price
FROM (
	SELECT product_id, new_price, change_date, rank() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS rk
	FROM (
		SELECT product_id, new_price, change_date
		FROM (
			SELECT product_id, new_price, change_date, rank() OVER (PARTITION BY product_id ORDER BY change_date) AS rk
			FROM Products
		) a
		WHERE a.rk = 1
			OR a.change_date <= '2019-08-16'
	) b
) a
WHERE a.rk = 1
```
