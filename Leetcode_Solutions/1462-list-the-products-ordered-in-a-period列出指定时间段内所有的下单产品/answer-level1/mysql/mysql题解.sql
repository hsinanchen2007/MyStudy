select P.product_name,sum(O.unit) unit
from Products P,Orders O
where P.product_id=O.product_id and (O.order_date between "2020-02-01" and "2020-02-29")
group by P.product_name
having unit>=100