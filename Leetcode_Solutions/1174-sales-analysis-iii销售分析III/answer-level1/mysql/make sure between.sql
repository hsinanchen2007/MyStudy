### 解题思路
此处撰写解题思路

### 代码

```mssql
/* Write your T-SQL query statement below */

select s.product_id, product_name from Sales s
inner join Product p on s.product_id=p.product_id 
group by s.product_id, product_name having max(sale_date)<='2019-03-31' and min(sale_date)>='2019-01-01'
```