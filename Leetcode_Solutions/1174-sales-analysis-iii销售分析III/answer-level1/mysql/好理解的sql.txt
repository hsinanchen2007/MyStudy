### 解题思路
好理解的sql

### 代码

```mysql
# Write your MySQL query statement below
select product_id ,product_name  from Product where  product_id in(
    select product_id from Sales group by product_id  having min(sale_date )>= '2019-01-01' and max(sale_date )<='2019-03-31'
   
)
```