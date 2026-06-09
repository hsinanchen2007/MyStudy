### 解题思路
产品都买的话，，，那么显然数量应该是一样的？题目没说还可以买不在产品列表的话就可以了

### 代码

```mysql
# Write your MySQL query statement below





select tmp.customer_id customer_id
from(
    select customer_id,count(distinct product_key) cnt
    from Customer
    group by customer_id
) tmp
where tmp.cnt =(
    select count(*)
    from Product
)
order by tmp.customer_id


```