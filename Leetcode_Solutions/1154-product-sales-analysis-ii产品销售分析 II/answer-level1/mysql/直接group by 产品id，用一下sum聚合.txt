### 解题思路
按产品id分组然后数一下一共销售了多少

### 代码

```mysql
# Write your MySQL query statement below
select product_id,sum(quantity) total_quantity
from Sales
group by product_id;
```