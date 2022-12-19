#好玩的sql还是没多少
```
# Write your MySQL query statement below

SELECT round(SUM(CASE 
		WHEN order_date = customer_pref_delivery_date THEN 1
		ELSE 0
	END) * 100 / COUNT(*), 2) AS immediate_percentage
FROM Delivery
```
