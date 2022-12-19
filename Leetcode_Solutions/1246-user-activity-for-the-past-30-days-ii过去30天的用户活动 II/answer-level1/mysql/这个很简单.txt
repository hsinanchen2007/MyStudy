### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
# 查询以查找截至2019年7月27日（含）的30天内每个用户的平均会话数，四舍五入到小数点后两位。
# 我们要为用户计算的会话是在该时间段内至少进行了一项活动的会话。

select  round(ifnull(avg(a.session_num), 0), 2) as average_sessions_per_user
from
(select user_id, count(distinct session_id) as session_num
from Activity
where
   activity_date between date_sub('2019-07-27', interval 29 day) and '2019-07-27'
group by  user_id) a


```