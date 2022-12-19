### 解题思路
排序用 窗口函数。和1076一个解法

### 代码

```mssql
/* Write your T-SQL query statement below */
select seller_id 
from
( 
select s.seller_id, dense_rank() over (order by sum(s.price) desc) as num
from product p join sales s 
on p.product_id = s.product_id 
group by s.seller_id 
) t
where t.num = 1;
```