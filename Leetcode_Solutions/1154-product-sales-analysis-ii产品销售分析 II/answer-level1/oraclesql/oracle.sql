```
-- 第一种
/* Write your PL/SQL query statement below */
-- select product_id,sum(quantity) total_quantity
-- from sales
-- group by product_id;

--第二种
select  distinct product_id,sum(quantity) over(partition by product_id order by product_id) total_quantity
from sales;


```
