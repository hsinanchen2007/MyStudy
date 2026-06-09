讲道理，不是mysql8.0版本可以用窗口函数了吗？

首先我们针对Orders表，用窗口函数，把每个seller_id卖出的第二件商品的品牌号码item_id搞出来：
```
select 
        seller_id,item_id
    from 
        (select 
            seller_id,item_id,
            rank() over(partition by seller_id order by order_date) as rank
        from   
            Orders
        ) tmp
    where 
        rank=2
```
然后考虑上表和Users表、Items表如何连接：
由于上表没有seller_id是1的情况，然而结果中user_id是1的情况也需要列出来，所以一定会用到left/right join连接。
可以先将Items表和上表o连接，对表o中每一个item_id都得到其对应的item_brand，然后再用right join与Users表连接，保留user_id的每一个取值：
```
select 
    *
from 
    Items i  
inner join
    (select 
        seller_id,item_id
    from 
        (select 
            seller_id,item_id,
            rank() over(partition by seller_id order by order_date) as rank
        from   
            Orders
        ) tmp
    where 
        rank=2
    ) o
on 
    i.item_id=o.item_id
right join 
    Users u 
on 
    o.seller_id=u.user_id
```
最后根据题目要求进行一些边角处理，首先提取出u表的user_id，然后用case when判断其对应的i.item_brand和u.favorite_brand是否相等，注意这里可能会出现与Null比较的情况，但是用else的话就将这种情况囊括其中了。
mysql写case when的时候可以用括号括起来，但是oracle不行，并且oracle的列命名必须用双引号，而不能用单引号。

```
select 
    u.user_id as seller_id,
    case when i.item_brand=u.favorite_brand then 'yes'
    else 'no' end as "2nd_item_fav_brand"
from 
    Items i  
inner join
    (select 
        seller_id,item_id
    from 
        (select 
            seller_id,item_id,
            rank() over(partition by seller_id order by order_date) as rank
        from   
            Orders
        ) tmp
    where 
        rank=2
    ) o
on 
    i.item_id=o.item_id
right join 
    Users u 
on 
    o.seller_id=u.user_id
order by 
    seller_id
```
