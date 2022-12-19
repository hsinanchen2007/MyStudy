
```SQL
SELECT ROUND(
    (SELECT COUNT(delivery_id)
    FROM Delivery
    WHERE order_date = customer_pref_delivery_date)
    * 100 / COUNT(delivery_id)
        , 2) 
AS immediate_percentage
FROM Delivery;
```