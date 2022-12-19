### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select U1.user_id as buyer_id, U1.join_date, 
count(rhs.item_id) as orders_in_2019
from
Users as U1
left join
(select * from Orders
where date_format(order_date, '%Y') = 2019) as rhs
on U1.user_id = rhs.buyer_id
group by 1,2
```