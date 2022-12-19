### 解题思路

临时表在join的时候 不要忘记 purchase_date 需要在 start_date 和 end_date中，每个时间段的价格都不同，分组group by 也最好带上 purchase_date，这样的话方便计算 
### 代码

```mysql
# Write your MySQL query statement below

select t.product_id, round((sum(t.price_day)/sum(t.units)),2) as average_price 
from 
(	select 
		p.product_id, u.purchase_date, p.price * u.units as price_day, units 
	from Prices p join UnitsSold u
		on p.product_id = u.product_id
		and u. purchase_date between p.start_date and p.end_date
	group by p.product_id, u.purchase_date
) t
group by t.product_id;
```