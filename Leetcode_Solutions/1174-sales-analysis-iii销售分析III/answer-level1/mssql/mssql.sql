### 代码

```mssql
/* Write your T-SQL query statement below */
select distinct product_id,product_name from
(select s.*,p.product_name,p.unit_price from Sales s
left join Product p
on s.product_id = p.product_id) t
where sale_date between '2019-01-01' and '2019-04-01'
and product_id not in(select product_id from Sales where sale_date < '2019-01-01' or sale_date > '2019-04-01')
```