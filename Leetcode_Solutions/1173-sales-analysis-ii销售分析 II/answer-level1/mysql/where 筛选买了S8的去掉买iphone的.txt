select distinct(buyer_id) from sales join product on sales.product_id=product.product_id 
where 
product.product_name="S8" 
and 
buyer_id not in  
 (select buyer_id from sales join product on sales.product_id=product.product_id where product.product_name="iphone" )