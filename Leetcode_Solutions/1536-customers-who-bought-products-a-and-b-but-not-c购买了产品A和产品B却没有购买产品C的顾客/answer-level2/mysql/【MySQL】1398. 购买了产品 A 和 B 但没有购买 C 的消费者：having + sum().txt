#### 思路 ####
- 根据`customer_id`连接`customers`表和`orders`表并分组
- 借助`sum()`函数统计各产品的购买数，并用`having`筛选出符合要求的消费者
#### 代码 ####
```mysql []
select c.customer_id,  customer_name
from customers c join orders o
on c.customer_id = o.customer_id
group by c.customer_id
having sum(product_name = 'A') and sum(product_name = 'B') and not sum(product_name = 'C')
```
