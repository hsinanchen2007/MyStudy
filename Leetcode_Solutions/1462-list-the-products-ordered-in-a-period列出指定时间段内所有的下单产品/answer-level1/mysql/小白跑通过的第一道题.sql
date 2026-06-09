纪念一下自己跑对的第一道题。思路：连接两个表，然后先用时间筛一遍，再分组，having子句求和，利用100最后筛一遍。
```
select p.product_name as product_name,sum(o.unit) as UNIT
from products as p left join orders as o on p.product_id = o.product_id
where order_date between'2020-02-01' and '2020-02-29'
group by p.product_name
having sum(o.unit)>=100
order by p.product_name desc;
```
