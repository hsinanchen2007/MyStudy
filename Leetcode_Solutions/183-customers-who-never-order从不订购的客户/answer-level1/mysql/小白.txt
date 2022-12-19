```
select a.name as Customers
from customers a
WHERE a.id not in (select c.id from customers c join orders o
on c.id = o.customerID)
```
