
在2019年1季度销售过的产品，其数据可分为两部分内容：
1. 在2019年1季度销售过，且在其他时间（非2019年1季度）也有销售记录的产品；
2. 在2019年1季度销售过，且在其他时间（非2019年1季度）没有销售记录的产品。

要求得 **只在2019年1季度有销售记录** 的产品，则只需要做下求差集运算即可：

```sql
select
	p.product_id,
	p.product_name
from product p, sales s
where p.product_id = s.product_id and s.sale_date >= '2019-01-01' and s.sale_date <= '2019-03-31'
minus
select
	p.product_id,
	p.product_name
from product p, sales s
where p.product_id = s.product_id and (s.sale_date < '2019-01-01' or s.sale_date > '2019-03-31')
```
