select product_id,sum(quantity) total_quantity
from Sales
group by product_id