思路：

1、先找到所有买了A产品的客户；<br>
2、再找到所有买了B产品的客户；<br>
3、然后找出既买了A产品，又买了B产品的客户，在这些客户中找到那些没有买C产品的客户即可。
```
select a.customer_id,d.customer_name
from (
    select customer_id
    from Orders
    where product_name='A'
) a
inner join(
    select customer_id
    from Orders
    where product_name='B'
) b on a.customer_id=b.customer_id
left join(
    select customer_id
    from Orders
    where product_name='C'
) c on a.customer_id=c.customer_id
left join Customers d on a.customer_id=d.customer_id
where c.customer_id is null
```
执行用时 :410 ms，内存消耗 :0B