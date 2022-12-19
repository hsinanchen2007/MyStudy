### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select min(round(sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)),2)) as shortest 
from point_2d a cross join point_2d b
where (a.x,a.y,b.x,b.y) not in (
    select * from point_2d c cross join point_2d d
    where c.x=d.x and c.y=d.y
)


```