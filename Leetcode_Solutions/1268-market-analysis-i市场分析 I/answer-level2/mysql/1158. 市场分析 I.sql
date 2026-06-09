### 解题思路
此处撰写解题思路
1.extract 用于截取2009年，配合sum(if())
2.左连接
### 代码

```mysql
# Write your MySQL query statement below

select a.user_id as buyer_id,a.join_date,sum(if(extract(year from b.order_date) = 2019,1,0)) as orders_in_2019 
from Users a left outer join Orders b
on a.user_id = b.buyer_id
group by a.user_id 
#order by a.user_id



```