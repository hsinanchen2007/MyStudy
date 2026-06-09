select round(ifnull(100 * avg(ontime),0), 2) immediate_percentage  from (select if(order_date = customer_pref_delivery_date, 1, 0) as ontime
from Delivery) t
