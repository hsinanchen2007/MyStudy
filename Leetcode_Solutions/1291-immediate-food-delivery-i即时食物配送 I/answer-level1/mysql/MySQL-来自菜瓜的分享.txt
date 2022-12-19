### 解题思路

配送日期和下单日期相同，则该订单称为 「即时订单」
所占的比例 保留两位小数。
round(  (即时订单/count(delivery_id))*100   ,2)

### 代码

```mysql
# Write your MySQL query statement below
select  round(
    (
        (
            select count(distinct delivery_id) as delivery
            from Delivery 
            where order_date = customer_pref_delivery_date 
        )
        /
        (
            select count(delivery_id ) from Delivery
        )
    )*100
            ,2) as immediate_percentage 
```