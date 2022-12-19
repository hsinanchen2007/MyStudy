### 解题思路
此处撰写解题思路
1.左连接算出垃圾邮件的移除率
2.求移除率的平均值
### 代码

```mysql
# Write your MySQL query statement below

select round(avg(t.avg_per),2) as average_daily_percent 
from
(
    select count(distinct b.post_id)/count(distinct a.post_id)*100 as avg_per
    from Actions a left outer join Removals b
    on a.post_id = b.post_id
    where a.extra="spam"
    group by a.action_date
)t



```