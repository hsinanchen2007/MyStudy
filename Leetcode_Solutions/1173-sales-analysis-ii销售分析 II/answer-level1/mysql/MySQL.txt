select distinct(t2.buyer_id) buyer_id

from Product t1

right join Sales t2

on t1.product_id=t2.product_id

where product_name in ('S8')

and buyer_id not in

(

select t4.buyer_id buyer_id

from Product t3

right join Sales t4

on t3.product_id=t4.product_id

where product_name in ('iPhone')

)
