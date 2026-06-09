
# Write your MySQL query statement below
#找出某一产品在最接近8月16号的那次修改的new_price as price，如果8月16号之前没有修改过，则为10
#mysql注释最好用#，不然会报错
select distinct product_id, 
    ifnull (
        (
            select t1.new_price
            from products t1
             where t1.product_id = t0.product_id
             and change_date <= '2019-08-16'
            order by t1.change_date desc 
            limit 1
        ),10
    ) as price
from Products t0