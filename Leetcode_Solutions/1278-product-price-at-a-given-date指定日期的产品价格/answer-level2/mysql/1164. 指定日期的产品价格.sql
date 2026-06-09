### 解题思路
此处撰写解题思路
分两个集合来做
一个集合是被改过加个的
另一个是没有改过价格的
### 代码

```mysql
# Write your MySQL query statement below




select product_id,new_price as price
from Products a
where (product_id,change_date) in
(
    select p1.product_id,max(p1.change_date)
    from Products p1 
    where p1.change_date <= '2019-08-16'
    group by p1.product_id
)

union 
select product_id ,10 as price 
from Products b
where (product_id) not in
(
    select p1.product_id
    from Products p1 
    where p1.change_date <= '2019-08-16'
    group by p1.product_id
)
```