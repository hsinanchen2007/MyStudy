#### 思路 ####
- 连接`Prices`表和`UnitsSold`表，要求`product_id`一致，且`purchase_date`在`start_date`与`end_date`之间
- 根据`product_id`分组
- 计算平均值并保留两位小数
#### 代码 ####
```mysql []
select p.product_id, round(sum(p.price * u.units) / sum(u.units), 2) as average_price
from Prices p inner join UnitsSold u
on p.product_id = u.product_id and u.purchase_date between p.start_date and p.end_date
group by p.product_id
```

