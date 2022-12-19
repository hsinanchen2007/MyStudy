### 解题思路
1.排序找出每个用户的首条记录
2.根据日期差值计算是否是即时订单
3.计算即时比例，处理小数点保留两位

### 代码

```mysql
# Write your MySQL query statement below

SELECT round(COUNT(if(df = 0, 1, NULL)) * 100 / COUNT(1), 2) AS immediate_percentage
FROM (
	SELECT customer_id
		, @rank := if(@last_user_id = customer_id, @rank + 1, 1) AS rank
		, datediff(customer_pref_delivery_date, order_date) AS df
		, @last_user_id := customer_id
	FROM Delivery, (
			SELECT @rank := 0, @last_user_id := NULL
		) temp
	ORDER BY customer_id ASC, order_date ASC
) a
WHERE rank = 1
```