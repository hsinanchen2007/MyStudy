### 解题思路
1.简单看懂英文
2.空值处理
### 代码

```mysql
# Write your MySQL query statement below

select u.name,ifnull(sum(r.distance),0) travelled_distance 
from users u
left join rides r
on u.id=r.user_id
group by user_id 
order by travelled_distance desc,u.name asc
```