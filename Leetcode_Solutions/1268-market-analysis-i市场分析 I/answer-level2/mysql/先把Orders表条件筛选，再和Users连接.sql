```
# Write your MySQL query statement below
select 
    u.user_id as buyer_id,join_date,count(order_id) as orders_in_2019
from 
    Users u 
left join 
    (select 
        *
    from 
        Orders
    where 
        date_format(order_date,'%Y')='2019'
    ) o 
on 
    u.user_id=o.buyer_id
group by 
    u.user_id

```
