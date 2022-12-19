### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select name,ifnull(sum(distance),0) travelled_distance
from rides right join users 
on rides.user_id = users.id
group by name
order by travelled_distance desc,name asc
```