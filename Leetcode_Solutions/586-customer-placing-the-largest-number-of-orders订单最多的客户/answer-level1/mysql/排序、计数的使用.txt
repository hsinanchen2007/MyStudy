### 解题思路
1.对订单进行计数，降序排列，可以找到最多的订单是哪个顾客
2.可能存在并列，所以对应题目取1

### 代码

```mysql
# Write your MySQL query statement below
select customer_number
from orders
group by customer_number
order by count(*) desc
limit 1

```