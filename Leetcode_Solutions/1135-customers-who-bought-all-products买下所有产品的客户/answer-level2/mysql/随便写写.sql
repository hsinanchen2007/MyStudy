### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select customer_id
from
Customer
group by 1
having count(distinct product_key) = (select count(product_key) from Product)
```