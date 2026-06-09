### 解题思路
此处撰写解题思路

### 代码

```mysql

#每天仅使用手机端用户
select d.spend_date, d.platform, ifnull(c.total_amount,0) as total_amount, ifnull(c.total_users,0) as total_users
from 
(select a.spend_date, 'mobile' platform,  sum(a.amount) as total_amount,count(distinct a.user_id) as total_users
from 
  Spending a
left join
  (select user_id, spend_date, count(distinct platform) as platform_num 
   from Spending
   group by user_id, spend_date) b
on a.user_id = b.user_id and a.spend_date = b.spend_date 
where  b.platform_num = 1 and a.platform = 'mobile'
group by  a.spend_date
union
#仅使用桌面端用户
select a.spend_date, 'desktop' platform,  sum(a.amount) as total_amount,count(distinct a.user_id) as total_users
from 
  Spending a
left join
  (select user_id, spend_date, count(distinct platform) as platform_num 
   from Spending
   group by user_id, spend_date) b
on a.user_id = b.user_id and a.spend_date = b.spend_date 
where  b.platform_num = 1 and a.platform = 'desktop'
group by  a.spend_date
union

#同时 使用桌面端和手机端
select a.spend_date, 'both' platform,  sum(a.amount) as total_amount,count(distinct a.user_id) as total_users
from 
  Spending a
left join
  (select user_id, spend_date, count(distinct platform) as platform_num 
   from Spending
   group by user_id, spend_date) b
on a.user_id = b.user_id and a.spend_date = b.spend_date 
where  b.platform_num = 2 
group by  a.spend_date) c right join (select distinct(spend_date), p.platform
from Spending, (select 'desktop' as platform union select 'mobile' as platform union select 'both' as platform ) as p) d on c.spend_date = d.spend_date and c.platform = d.platform









```