```
/* Write your PL/SQL query statement below */
SELECT user_id AS buyer_id, to_char(MAX(join_date),'yyyy-MM-dd') AS join_date, SUM(CASE 
		WHEN b.buyer_id is not NULL THEN 1
		ELSE 0
	END) AS orders_in_2019
FROM Users a
	LEFT JOIN Orders b
	ON a.user_id = b.buyer_id
		AND to_char(b.order_date, 'yyyy') = 2019
GROUP BY a.user_id


```
