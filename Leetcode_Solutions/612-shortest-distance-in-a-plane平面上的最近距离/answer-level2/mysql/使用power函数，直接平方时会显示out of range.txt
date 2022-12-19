### 解题思路
not (p1.x,p1.y)=(p2.x,p2.y)等价于p1.x!=p2.x or p1.y!=p2.y
### 代码

```mysql
# Write your MySQL query statement below
select min(
round(
sqrt(
power((p1.x-p2.x),2)+power((p1.y-p2.y),2)
)
,2)
) shortest
from point_2d p1
left join point_2d p2
on p1.x!=p2.x or p1.y!=p2.y;
```