查找出最高值后根据最高值确定显示的id.
```
select seller_id 
from sales 
group by seller_id having sum(price) = (
    select sum(price) total 
    from sales 
    group by seller_id 
    order by total desc
    limit 1
) ;
```
