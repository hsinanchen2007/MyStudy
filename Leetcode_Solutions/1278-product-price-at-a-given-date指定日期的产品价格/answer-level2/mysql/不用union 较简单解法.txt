# Write your MySQL query statement below
select distinct product_id,(case when change_date>'2019-08-16' then 10 else new_price end)as price
from Products
where (product_id,change_date) in (select product_id,max(change_date) 
                                   from Products 
                                   where change_date<='2019-08-16' 
                                   group by product_id ) 
      or (change_date>'2019-08-16' and product_id not in (select distinct product_id from Products where change_date<='2019-08-16'))