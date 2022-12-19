### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

# 在被报告为垃圾广告的帖子中，被移除的帖子的每日平均占比，四舍五入到小数点后 2 位。


select round(avg(c.daily_percent)*100, 2) average_daily_percent
from 
(select a.action_date, count(distinct b.post_id)/count(distinct a.post_id) as daily_percent
from 
(# 垃圾广告的帖子
select * 
from 
   Actions
where action = 'report' and extra = 'spam') a left join Removals b
on a.post_id = b.post_id and a.action_date <= b.remove_date
group by a.action_date) c
```