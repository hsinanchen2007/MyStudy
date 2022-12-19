```
/* Write your PL/SQL query statement below */
select customer_number
from orders
group by customer_number
having count(*)>=all(
        select count(*)  over(partition by customer_number) from orders);
```
