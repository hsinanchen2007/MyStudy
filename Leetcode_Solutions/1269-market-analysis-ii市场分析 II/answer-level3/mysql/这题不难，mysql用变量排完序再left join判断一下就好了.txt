先按照seller_id,order_date排序,再用变量得到每一行的rank值,如下所示:
```
select order_id,order_date,item_id,buyer_id,seller_id,
cast(if(@prev = seller_id,@rank := @rank + 1,@rank := 1) as unsigned) as rank,
@prev := seller_id as prev
from 
(select order_id,order_date,item_id,buyer_id,seller_id
from Orders
group by seller_id,order_date) as t1,
(select @rank := 0,@prev := null) as init
```
得到上述结果之后,再和Items表关联得到rank=2的数据,如下所示:
```
select order_id,order_date,t2.item_id,buyer_id,seller_id,
i.item_brand as item_brand
from 
(select order_id,order_date,item_id,buyer_id,seller_id,
cast(if(@prev = seller_id,@rank := @rank + 1,@rank := 1) as unsigned) as rank,
@prev := seller_id as prev
from 
(select order_id,order_date,item_id,buyer_id,seller_id
from Orders
group by seller_id,order_date) as t1,
(select @rank := 0,@prev := null) as init) t2,Items i
where rank = 2 and t2.item_id = i.item_id
```
最后再和Users表左连接,判断一下结果就行了,如下所示:
```
select user_id as seller_id,
(
    case when t3.item_brand is null then 'no'
         when t3.item_brand = u.favorite_brand then 'yes'
    else 'no' end
) as 2nd_item_fav_brand
from Users u
left join 
(select order_id,order_date,t2.item_id,buyer_id,seller_id,
i.item_brand as item_brand
from 
(select order_id,order_date,item_id,buyer_id,seller_id,
cast(if(@prev = seller_id,@rank := @rank + 1,@rank := 1) as unsigned) as rank,
@prev := seller_id as prev
from 
(select order_id,order_date,item_id,buyer_id,seller_id
from Orders
group by seller_id,order_date) as t1,
(select @rank := 0,@prev := null) as init) t2,Items i
where rank = 2 and t2.item_id = i.item_id) as t3
on u.user_id = t3.seller_id
```
