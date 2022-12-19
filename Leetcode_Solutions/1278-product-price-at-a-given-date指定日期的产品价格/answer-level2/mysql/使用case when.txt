min,max change_date ,case when 语句，不过非常的慢


select a.product_id,
case
when min(change_date)<="2019-08-16" then 
(select new_price from Products c 
where c.product_id=a.product_id and c.change_date in (
select max(change_date) from Products r
where r.change_date<="2019-08-16"
group by r.product_id
 having r.product_id=a.product_id))
else 10 end price 
from Products a 
group by a.product_id
