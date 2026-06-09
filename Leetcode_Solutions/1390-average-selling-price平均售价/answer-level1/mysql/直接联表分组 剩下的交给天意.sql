### 解题思路
直接联表分组然后除就完事儿了

### 代码

```mysql
# Write your MySQL query statement below


select p.product_id,round(sum(u.units*price)/sum(u.units),2) `average_price` from Prices p left join UnitsSold u on p.product_id = u.product_id and u.purchase_date between p.start_date and p.end_date group by p.product_id
```