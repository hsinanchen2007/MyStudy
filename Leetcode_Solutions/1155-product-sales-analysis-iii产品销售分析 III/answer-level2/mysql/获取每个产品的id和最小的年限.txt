### 解题思路
首先获取每个产品的id和最小的年限一查就好
### 代码

```mysql
# Write your MySQL query statement below


select product_id,`year` first_year,quantity,price from Sales where (product_id,year) in 
(select product_id,min(year) from Sales group by product_id)
```