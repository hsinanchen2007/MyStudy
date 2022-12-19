### 解题思路
比较白痴的方法。。长一点的日期就没法对付了

### 代码

```mysql
# Write your MySQL query statement below
#t是头尾的时间

select distinct p.product_id as PRODUCT_ID,product_name AS PRODUCT_NAME,concat(year(period_start),'') as REPORT_YEAR,(datediff(period_end,period_start)+1)*average_daily_sales as  TOTAL_AMOUNT
from
    (select product_id,period_start,if(DATE_ADD(concat(year(period_start)+1,'-01-01'),INTERVAL -1 day)<period_end,DATE_ADD(concat(year(period_start)+1,'-01-01'),INTERVAL -1 day),period_end) 
    as period_end,average_daily_sales  from Sales
    union all
    select product_id,if(concat(year(period_end),'-01-01')<period_start,period_start,concat(year(period_end),'-01-01')) AS period_start,period_end,average_daily_sales from Sales 
    union all
    select product_id,if(DATE_ADD(concat(year(period_start)+2,'-01-01'),INTERVAL -1 day)between  period_start and period_end,DATE_ADD(concat(year(period_start)+2,'-01-01'),INTERVAL -1 year),period_end) 
    as period_start,if(DATE_ADD(concat(year(period_start)+2,'-01-01'),INTERVAL -1 day)between  period_start and period_end,DATE_ADD(concat(year(period_start)+2,'-01-01'),INTERVAL -1 day),period_end) 
    as period_end,average_daily_sales from Sales where year(period_end) - year(period_start)>1


    ) p
left join Product 
on  p.product_id = Product.product_id 
order by  product_id ,report_year



```