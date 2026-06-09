执行用时 : 224 ms, 在所有 MySQL 提交中击败了42.59%的用户
内存消耗 : 0B, 在所有 MySQL 提交中击败了100.00%的用户
```
SELECT ROUND(100*SUM(IF(order_date = customer_pref_delivery_date, 1, 0))/COUNT(order_date), 2) AS immediate_percentage
FROM Delivery
```
