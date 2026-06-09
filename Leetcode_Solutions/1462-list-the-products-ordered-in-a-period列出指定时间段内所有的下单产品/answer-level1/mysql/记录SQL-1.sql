### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select a.product_name as PRODUCT_NAME ,sum(b.unit)as UNIT 
from Products a left join Orders b on a.product_id =b.product_id
where order_date >='20200201'
and order_date <='20200229'
group by a.product_name
having sum(b.unit) >=100
```