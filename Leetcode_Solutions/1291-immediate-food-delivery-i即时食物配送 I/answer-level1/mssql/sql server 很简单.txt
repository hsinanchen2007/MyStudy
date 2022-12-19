```sql
select 
round((CAST(COUNT(delivery_id) as float) /(select CAST(COUNT(delivery_id)AS float) from Delivery)*100),2) as immediate_percentage
from Delivery where order_date=customer_pref_delivery_date;
```
count 出数量需要用cast转换成float。
