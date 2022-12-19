```
select product_name, s.year, s.price
from product p
join sales s using(product_id);
```
