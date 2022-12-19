### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select u.user_id as buyer_id  ,u.join_date as join_date  ,ifnull(t.num,0) as orders_in_2019 
from 
Users u left outer join 
(select buyer_id,count(order_id) as num
from Orders 
where extract(year from order_date)=2019
group by buyer_id ) t
on u.user_id = t.buyer_id


```