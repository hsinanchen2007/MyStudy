### 解题思路
难点在于在用LEFT JOIN的时候，确保选择的是唯一的product id。因为临时表也去重了，这样在做连接的时候，数据都是唯一的。

### 代码

```mysql
# Write your MySQL query statement below
select p.product_id,ifnull(temp.new_price,10) as price
from (select distinct product_id from products) p 
left join
    (select p.product_id,p.new_price
    from Products p 
    where (p.product_id,p.change_date) in
    (select product_id,max(change_date) as change_date
    from Products p 
    where change_date <= '2019-08-16'
    group by product_id) ) temp
on p.product_id = temp.product_id
