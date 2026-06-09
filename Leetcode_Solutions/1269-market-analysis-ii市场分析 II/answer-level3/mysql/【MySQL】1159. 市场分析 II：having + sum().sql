#### 思路 ####
- `orders`根据`seller_id`自连接，根据`order_id`分组
- 使用`sum()`统计比当前订单日期更早的订单数，若为`1`，说明当前订单是对应用户卖出的第二单
- 根据`item_id`与`items`连接，将商品编号转化为品牌名
- `users`左连接上述的子查询，判断是否为用户最喜爱的品牌
#### 代码 ####
```mysql []
# 双层
select user_id seller_id, if(favorite_brand = item_brand, 'yes', 'no') 2nd_item_fav_brand
from users left join (
    select o1.seller_id, item_brand
    from orders o1 
    join orders o2
    on o1.seller_id = o2.seller_id
    join items i
    on o1.item_id = i.item_id
    group by o1.order_id
    having sum(o1.order_date > o2.order_date) = 1
) tmp
on user_id = seller_id
```
```mysql []
# 三层
select user_id seller_id, if(favorite_brand = item_brand, 'yes', 'no') 2nd_item_fav_brand
from users left join (
    select seller_id, item_brand
    from (
        select o1.seller_id, o1.item_id
        from orders o1 join orders o2
        on o1.seller_id = o2.seller_id
        group by o1.order_id
        having sum(o1.order_date > o2.order_date) = 1
    ) o join items i
    on o.item_id = i.item_id
) tmp
on user_id = seller_id
```

