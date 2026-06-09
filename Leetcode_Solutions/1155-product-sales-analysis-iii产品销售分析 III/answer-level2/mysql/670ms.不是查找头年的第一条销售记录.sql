### 解题思路
where原来是可以嵌套几个的呀

### 代码

```mysql
# Write your MySQL query statement below
#每种产品第一年的所有销售记录（不是第一条销售记录）
select   product_id,year as first_year ,quantity,price 
from sales where (product_id,year) in
(select product_id,min(year) as first_year 
from sales 
group by product_id ) 
```