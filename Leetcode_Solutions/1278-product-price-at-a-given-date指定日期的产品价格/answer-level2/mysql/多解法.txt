### 使用 join+union

```mysql
# 在2019-08-16 前改过的产品价格为2019-08-16前改的最后一个价格
select p3.product_id,p3.new_price price
from products p3
inner join (
    select p4.product_id,max(change_date) lastDate
    from products p4
    where p4.change_date<='2019-08-16'
    group by product_id # 选2019-08-16前的并分组求出最后修改时间
)tmp on p3.change_date=tmp.lastDate # 通过日期join起来
and p3.product_id=tmp.product_id
union all
# 在2019-08-16 前没有改过的产品价格为10
select distinct p1.product_id,10 price
from products p1
where p1.product_id not in(
    # 找出所有的再2019-08-16 前改过价格的产品
    select p2.product_id
    from products p2
    where p2.change_date<='2019-08-16'
)
```
### 使用 where+union
```mysql
# 在2019-08-16 前改过的产品价格为2019-08-16前改的最后一个价格
select p3.product_id,p3.new_price price
from products p3
where (p3.product_id,p3.change_date) in (
    select p4.product_id,max(change_date) lastDate
    from products p4
    where p4.change_date<='2019-08-16'
    group by product_id # 选2019-08-16前的并分组求出最后修改时间
)
union all
# 在2019-08-16 前没有改过的产品价格为10
select distinct p1.product_id,10 price
from products p1
where p1.product_id not in(
    # 找出所有的再2019-08-16 前改过价格的产品
    select p2.product_id
    from products p2
    where p2.change_date<='2019-08-16'
)
```
### 使用left join+ifnull
```mysql
select p3.product_id,ifnull(tmp.price,10) price
from (
    # 给产品id去重
    select distinct product_id
    from products
    )p3 
left join(
    select p2.product_id,p2.new_price price
    from products p2
    where (p2.product_id,p2.change_date) in 
        (
        # 所有在2019-08-16前修改的信息
        select p1.product_id,max(p1.change_date) lastDate
        from products p1
        where p1.change_date<='2019-08-16'
        group by p1.product_id
        )
)tmp on tmp.product_id=p3.product_id;
```