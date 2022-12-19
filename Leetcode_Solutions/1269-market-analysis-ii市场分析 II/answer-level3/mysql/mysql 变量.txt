```
select 
    u.user_id as seller_id, 
    if(isnull(s1.item_brand) ||(s1.item_brand != u.favorite_brand ) ,'no','yes') as 2nd_item_fav_brand 
from (
select 
    r.seller_id,
    i.item_brand 
from (
    select    
        seller_id,
        order_date,
        item_id,
        case when @seller = seller_id then @num := @num+1
            when @seller:=seller_id then @num:=1
            else @num:=1
        end as num 
    from Orders o,(select @num:=0,@prev:=0,@seller:=0) s 
order by seller_id,order_date
) r left join Items i on i.item_id=r.item_id
where num = 2
group by seller_id
)s1 right join Users u on u.user_id=s1.seller_id
```
