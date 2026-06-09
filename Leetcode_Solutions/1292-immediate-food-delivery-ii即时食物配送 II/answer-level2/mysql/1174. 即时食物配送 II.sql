### 解题思路
此处撰写解题思路
原表内连接用户的首次下单日期
### 代码

```mysql
# Write your MySQL query statement below

select round(sum(if(a.order_date = a.customer_pref_delivery_date ,1,0))/count(*)*100,2) as immediate_percentage 
from Delivery a inner join (
    select customer_id,min(order_date) as order_date
    from Delivery 
    group by customer_id 
)b
on a.customer_id = b.customer_id
where a.order_date =b.order_date




```