```
/* Write your PL/SQL query statement below */

select p.product_id,round(sum(price*units)/sum(units),2) average_price
from prices p,unitsSold us
where p.product_id=us.product_id(+) and 
        purchase_date<=end_date and 
        purchase_date>=start_date
group by p.product_id;

```
