```
select round(count(
    case when d.order_date = d.customer_pref_delivery_date then 1
    end
) * 100/count(*),2) as immediate_percentage
from Delivery d,
(select delivery_id,customer_id,min(order_date) as order_date
from Delivery
group by customer_id) as t
where d.customer_id = t.customer_id and d.order_date = t.order_date
```
