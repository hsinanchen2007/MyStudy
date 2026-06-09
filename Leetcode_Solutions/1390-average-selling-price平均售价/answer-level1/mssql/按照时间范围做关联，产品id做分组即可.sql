按照时间范围做关联，产品id做分组即可



/* Write your T-SQL query statement below */
select product_id,cast(sum(price*units)*1./sum(units) as decimal(18,2)) average_price from
(select a.product_id,price,units from Prices a
left join UnitsSold b
on (a.product_id = b.product_id and b.purchase_date between a.start_date and a.end_date)) t
group by product_id