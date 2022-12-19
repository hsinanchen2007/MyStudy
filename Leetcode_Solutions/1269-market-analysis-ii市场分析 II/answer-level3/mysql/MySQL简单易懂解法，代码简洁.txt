这题其实是选取部门第二高的工资数的复合题，在求出第二位的工资数后把结果和另外两个表连接一下就出结果了
```
select u.user_id seller_id,
case when item_brand is null or item_brand !=favorite_brand then 'no'else 'yes' end 2nd_item_fav_brand
from 
(
    select *
    from 
    (
        select a.*,if(@group!=a.seller_id,@rank:=0,@rank:=@rank+1) r, @group:=seller_id 
        from (select * from Orders order by seller_id,order_date)a,(select @group:='',@rank:=0)b
    )c
    where r=1
)t2
left join Items i on t2.item_id=i.item_id right join Users u on t2.seller_id=u.user_id

```
