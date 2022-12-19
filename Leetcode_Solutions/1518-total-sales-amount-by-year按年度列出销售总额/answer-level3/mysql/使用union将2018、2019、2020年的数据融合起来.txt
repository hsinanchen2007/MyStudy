### 解题思路
分别计算每条记录2018、2019和2020年的total_amount,然后用union将三年的数据融合起来

### 代码

```mysql
# Write your MySQL query statement below
(
 select Sales.product_id, product_name, '2018' as 'report_year', if(period_start<'2019-01-01', (datediff(if(period_end<'2019-01-01', period_end, date('2018-12-31')), if(period_start>='2018-01-01', period_start, date('2018-01-01')))+1)*average_daily_sales, 0) as total_amount
from Sales  
join Product on Sales.product_id = Product.product_id 
having  total_amount>0
)
union(
    select Sales.product_id, product_name, '2019' as 'report_year', if( period_start<'2020-01-01', (datediff(if(period_end<'2020-01-01', period_end, date('2019-12-31')), if(period_start>='2019-01-01', period_start, date('2019-01-01')))+1)*average_daily_sales , 0) as total_amount
from Sales  
join Product on (Sales.product_id = Product.product_id )
having  total_amount>0
)
union(
    select Sales.product_id, product_name, '2020' as 'report_year', (datediff(if(period_end<'2021-01-01', period_end, date('2020-12-31')), if(period_start>='2020-01-01', period_start, date('2020-01-01')))+1)*average_daily_sales as total_amount
from Sales  
join Product  on (Sales.product_id = Product.product_id)
having total_amount>0
) order by product_id, report_year

```