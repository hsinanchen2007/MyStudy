### 解题思路
根据题意，找出既关注了别人又被别人关注了的人，被关注的次数。被关注的次数可以直接在follow表里面统计，但是注意丢掉没有关注别人的，这些的名字不会出现在所有关注了别人的人中。
distinct是个巨大的坑啊

### 代码

```mysql
# Write your MySQL query statement below
select followee follower,count(distinct follower) num
from follow
where followee =any(
select distinct follower from follow)
group by followee
order by followee;


#select f1.follower follower, count(distinct(f2.follower)) num
#from follow f1
#inner join follow f2 on f1.follower=f2.followee
#group by f1.follower
#order by f1.follower;

```