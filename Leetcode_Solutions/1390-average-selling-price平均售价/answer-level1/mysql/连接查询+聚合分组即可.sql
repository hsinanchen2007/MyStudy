### 解题思路
连接查询即可

### 代码

```mysql
# Write your MySQL query statement below


select t.product_id,round(sum(t.su)/sum(t.units),2) average_price from 
(select p.product_id,p.price*u.units  as su,u.units
from Prices p
left join UnitsSold u
on p.product_id=u.product_id
where u.purchase_date between p.start_date and end_date) t
group by t.product_id


```