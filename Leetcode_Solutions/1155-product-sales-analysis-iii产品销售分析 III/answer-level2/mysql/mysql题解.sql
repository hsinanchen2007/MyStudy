第一种方法超时
/*select S.product_id product_id,S.year first_year,S.quantity,S.price
from Sales S,Product P
where S.product_id=P.product_id 
and S.year=(select min(year) from Sales where S.product_id=product_id group by S.product_id)
*/

最后发现其实并不需要用到Product这张表
select S.product_id,S.year first_year,S.quantity,S.price
from Sales S
where (S.product_id,S.year) in (select product_id,min(year) from Sales group by product_id)