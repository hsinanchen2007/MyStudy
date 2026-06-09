select users.user_id as seller_id, 'yes' 2nd_item_fav_brand
from users
where favorite_brand = (
select Items.item_brand 
from orders left join Items on orders.item_id = Items.item_id
where users.user_id = orders.seller_id
order by orders.order_date asc
limit 1,1)
union 
select  user_id, 'no' 2nd_item_fav_brand
from users
where users.user_id
not in 
(select users.user_id
from users
where favorite_brand = (
select Items.item_brand 
from orders left join Items on orders.item_id = Items.item_id
where users.user_id = orders.seller_id
order by orders.order_date asc
limit 1,1))
