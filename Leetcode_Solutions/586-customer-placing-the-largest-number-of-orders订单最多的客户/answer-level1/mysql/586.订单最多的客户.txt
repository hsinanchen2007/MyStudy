方法：通过`group by`分组后使用聚合函数`count`计算各个用户的订单数，再使用`order by`和`limit`子句来确定订单最多的客户。

```MySql
select customer_number
from 
(select customer_number,
    count(*) order_cnt    # 这里是因为order_number是主键，所以可以count(*)。如果一个订单对应多条记录，则需要count(distinct order_number)
 from orders
 group by customer_number) tmp
order by order_cnt desc
limit 1;
```

但是使用了临时表，通过在`order by`子句中使用聚合函数`count`可以使代码更简洁、高效：

```MySql
select customer_number
from orders
group by customer_number
order by count(*) desc
limit 1;
```