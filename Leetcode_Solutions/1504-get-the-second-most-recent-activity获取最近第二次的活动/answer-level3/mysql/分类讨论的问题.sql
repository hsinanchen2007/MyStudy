### 解题思路
关键在于把只有一行的用户筛选出来，然后用union链接其他用户的第二近活动。

### 代码

```mysql
# Write your MySQL query statement below
select *
from UserActivity
group by username
having count(startDate)=1
union
select *
from 
(select *
from UserActivity
where (username,startDate) not in 
(select username,max(startDate) from UserActivity group by username)) kk
where (username,startDate) in
(select username,max(startDate) from (select *
from UserActivity
where (username,startDate) not in 
(select username,max(startDate) from UserActivity group by username)) kk
group by username)



```