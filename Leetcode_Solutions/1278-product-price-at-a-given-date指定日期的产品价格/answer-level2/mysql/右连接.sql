select distinct p.product_id,
       if(p.product_id in (select product_id from products where change_date <="2019-08-16" group by product_id),if(p.change_date=a.mx,new_price,0),10) as price 
 from
 products p 
 left join
(select product_id,max(change_date) mx from products where change_date <="2019-08-16" group by product_id) a
on p.product_id=a.product_id
where if(p.product_id in (select product_id from products where change_date <="2019-08-16" group by product_id),if(p.change_date=a.mx,new_price,0),10)>0