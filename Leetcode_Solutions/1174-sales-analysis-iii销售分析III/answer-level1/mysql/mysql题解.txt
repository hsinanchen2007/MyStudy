select S.product_id,P.product_name
from Product P,Sales S
where P.product_id=S.product_id
group by product_id
having sum(S.sale_date not between "2019-01-01" and "2019-03-31")=0