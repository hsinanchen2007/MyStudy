### 解题思路
题意：习大大没有关注任何人，小明关注了习大大，求有少人关注了小明？哈哈
这才是二级关注者的意思

但是题目中并没有说 会有重复关注啊？
### 代码

```mysql
# Write your MySQL query statement below



select f.followee follower, count(distinct f.follower) num
from follow f  
where f.followee in (
    select f1.follower
    from follow f1 
)
group by f.followee
order by f.followee
```