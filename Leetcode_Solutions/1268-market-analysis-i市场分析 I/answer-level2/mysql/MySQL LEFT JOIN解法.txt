这道题只需要使用Users和Orders两个表，重点考察了LEFT JOIN的使用。
```
SELECT user_id AS buyer_id,
       join_date,
       IFNULL(COUNT(buyer_Id), 0) AS orders_in_2019
FROM Users u LEFT JOIN Orders o ON U.user_id = o.buyer_id AND order_date >= '2019-01-01'
GROUP BY user_id
ORDER BY user_id
```
