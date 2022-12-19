### 解题思路
此处撰写解题思路
本质上就是求每个客户买的不重复的商品数是否等于商品种类种数

### 代码

```mysql
# Write your MySQL query statement below

select customer_id 
from Customer
group by customer_id
having count(distinct product_key ) = (
    select count(distinct product_key) from Product  
)
```