### 解题思路
1 先把order表里面的采购了C的客户排除掉
2 CASE WHEN 构建2个辅助列。去掉购买过C，剩下的客户里面，如果买了A，则记录为1，否则0 作为num1；同理，如果买了B，则记录为1，否则0 作为num2。这样只要客户同时买了A,B，按id求和的话两列一定会同时大于0，如果客户只买了一种或者都没有买，则两列一定至少有一列为0。这个作为后面的筛选条件。
3 和customer表做内连接，然后使用group by，选出num1,num2同时大于0的id及对应的客户名称。

### 代码

```mysql
# Write your MySQL query statement below
select temp1.customer_id,customer_name
from
    (select customer_id,product_name,
    case when product_name = 'A' then 1 else 0 end as num1,
    case when product_name = 'B' then 1 else 0 end as num2
    from 
        (
        select * 
        from Orders
        where customer_id not in(
            select customer_id
            from Orders
            where product_name = 'C')) temp) temp1
inner join Customers cu 
on temp1.customer_id = cu.customer_id
group by temp1.customer_id
having sum(num1) >0 and sum(num2) >0
```