```
select s.buyer_id
from sales s, product p where s.product_id = p.product_id and p.product_name = 'S8'
minus
select s.buyer_id
from sales s, product p where s.product_id = p.product_id and p.product_name = 'iPhone'
```
