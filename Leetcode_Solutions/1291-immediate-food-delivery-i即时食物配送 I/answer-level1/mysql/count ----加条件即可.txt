### 解题思路


### 代码

```mysql
# Write your MySQL query statement below
select round(count(case when d.order_date=d.customer_pref_delivery_date 
then 1 else null end)/count(*)*100,2) immediate_percentage 
from delivery d
 
```