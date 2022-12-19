### 解题思路
三角形两边之和大于第三边，两边之差小于第三边

### 代码

```mysql
# Write your MySQL query statement below
select x,y,z,
case
when x+y>z and abs(x-y)<z then "Yes"
else "No"
end 
as triangle
from triangle;
```