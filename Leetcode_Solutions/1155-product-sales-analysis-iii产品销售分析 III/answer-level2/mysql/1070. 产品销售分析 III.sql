### 解题思路
此处撰写解题思路
重点在于 where in的使用
### 代码

```mysql
# Write your MySQL query statement below


select product_id,year as first_year,quantity,price
from  Sales s
where (s.product_id,s.year)
in (
    select  t.product_id,min(t.year) from Sales t group by t.product_id
)
```