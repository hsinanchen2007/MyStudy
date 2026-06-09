### 解题思路
用了近似lag的方法

### 代码

```mysql
# Write your MySQL query statement bel

(
    select c1.seat_id
from cinema c1,cinema c2
where (c1.seat_id = c2.seat_id -1) 
and c1.free *c2.free !=0
)
union
(
    select c2.seat_id
from cinema c1,cinema c2
where (c1.seat_id = c2.seat_id -1) 
and c1.free *c2.free !=0
)
order by seat_id

```