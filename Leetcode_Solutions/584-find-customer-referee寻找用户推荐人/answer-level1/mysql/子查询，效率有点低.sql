### 解题思路

### 代码

```mysql
# Write your MySQL query statement below
select name
from customer
where id not in(
    select id 
    from customer
    where referee_id = 2
);


```