题目需要查询出买AB但没买C的顾客
1. 生成一个临时表a，记录至少买过A/B/C商品之中的用户购买信息
where product_name in ('A','B','C') 至少买过A/B/C其中一个商品的客户
group by 按照customer_id分组
对于每个用户，利用case when 记录具体购买情况 （如果有买A就记1笔，没有买则为0）
最后进行求和，0表示用户没有买的商品

```
(select c.customer_id,c.customer_name
,sum(case when product_name='A' then 1 else 0 end) A
,sum(case when product_name='B' then 1 else 0 end) B
,sum(case when product_name='C' then 1 else 0 end) C
from Customers c left join Orders o 
on c.customer_id=o.customer_id
where product_name in ('A','B','C') 
group by c.customer_id,c.customer_name) a
```

2. 通过0来判断用户是否购买过某商品
我们需要的客户是 A != 0 and B != 0 and C =0
最后选出满足条件的顾客 order by id
(a：第一步生成的临时表)

```
select customer_id, customer_name from 
a 
where A != 0 and B != 0 and C =0
order by customer_id
```

