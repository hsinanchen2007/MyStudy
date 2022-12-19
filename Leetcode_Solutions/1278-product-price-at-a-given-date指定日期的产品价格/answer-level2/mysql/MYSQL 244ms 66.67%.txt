### 解题思路

1.提取distinct product_id
2.提取'2019-08-16'以前的最大日期的售价
3.join两个表格
4.用ifnull来补充原始售价10的id情况

### 代码

```mysql
# Write your MySQL query statement 

select a.product_id,ifnull(new_price,10) as price
from (
    select distinct product_id
    from products
) a left join (
    select product_id,new_price
    from products
    where (product_id,change_date) in(
        select product_id,max(change_date)
        from products
        where change_date<='2019-08-16'
        group by product_id
    )
) b on a.product_id = b.product_id
order by ifnull(new_price,10) desc







```