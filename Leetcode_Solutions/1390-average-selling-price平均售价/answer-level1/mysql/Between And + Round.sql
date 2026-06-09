# Write your MySQL query statement below
# 日期范围用between and
# 保留2位小数 round(x,2)

select product_id, round(sum(qian)/sum(units),2) average_price 
from(
    select a.product_id, a.price * b.units qian,b.units
    from Prices a
    join UnitsSold b on b.purchase_date between a.start_date and a.end_date
    and a.product_id = b.product_id) tmp
group by product_id