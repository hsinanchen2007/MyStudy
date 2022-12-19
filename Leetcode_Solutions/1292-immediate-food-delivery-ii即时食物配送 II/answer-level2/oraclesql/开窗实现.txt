/* Write your PL/SQL query statement below */
/*rank()开窗给order date，group by customer id，取rank 为1 的第一次下单*/
/*比较pref和order date是否同日 / 总共的第一单个数 */
SELECT ROUND(SUM(DECODE(order_date, customer_pref_delivery_date, 1,0)) / COUNT(customer_id) * 100,2) AS immediate_percentage
FROM(
    SELECT delivery_id, customer_id, order_date, customer_pref_delivery_date, rank()over(PARTITION BY customer_id ORDER BY order_date) AS rank 
    FROM Delivery
    )tmp 
WHERE tmp.rank = 1;