想不到这题竟然在'2nd_item_fav_brand'的单引号上面卡了很久....

```
select u.user_id seller_id,
    case when i.item_brand=u.favorite_brand then 'yes' 
    else 'no' end '2nd_item_fav_brand'
from Users u
left join (
    select seller_id,item_id,row_number() over(partition by seller_id order by order_date) rn
    from Orders
) t on u.user_id=t.seller_id and t.rn=2
left join Items i on t.item_id=i.item_id
order by u.user_id
```
执行用时 :2156 ms, 内存消耗 :0B