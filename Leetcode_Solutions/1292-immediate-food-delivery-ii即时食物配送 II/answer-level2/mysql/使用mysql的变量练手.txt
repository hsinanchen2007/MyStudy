#sql题不难，大部分中等题也就这个样子了，这里采用mysql变量达到开窗的效果，oracle直接就干rank就行了
```
# Write your MySQL query statement below

SELECT round(SUM(CASE 
		WHEN order_date = customer_pref_delivery_date THEN 1
		ELSE 0
	END) * 100 / COUNT(*), 2) AS immediate_percentage
FROM (
	SELECT customer_id, order_date, customer_pref_delivery_date
		, CASE 
			WHEN @preColumn = customer_id THEN @rk := @rk + 1
			ELSE @rk := 1
		END AS rk, @preColumn := customer_id
	FROM Delivery, (
			SELECT @preColumn := NULL, @rk := 0
		) r
	ORDER BY customer_id, order_date
) a
WHERE a.rk = 1
```
