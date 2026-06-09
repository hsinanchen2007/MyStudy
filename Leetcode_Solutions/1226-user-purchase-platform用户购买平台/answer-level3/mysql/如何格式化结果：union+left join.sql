# 利用union格式化最终结果(t2 left join t3)
select t2.*,ifnull(t3.total_amount,0)total_amount,ifnull(t3.total_users,0)total_users
from
(select spend_date,"desktop" platform
from Spending
group by Spend_date
union
select spend_date,"mobile" platform
from Spending
group by Spend_date
union
select spend_date,"both" platform
from Spending
group by Spend_date)t2 

left join

(select spend_date,tag platform,sum(total_amount) total_amount,count(tag) total_users
from
(select user_id,spend_date,sum(amount) total_amount,case when count(distinct platform)=2 then "both" when sum(platform="mobile")=0 then "desktop" else "mobile" end tag
from Spending
group by user_id,spend_date
order by spend_date,user_id)t1
group by spend_date,tag)t3
on t2.spend_date=t3.spend_date and t2.platform=t3.platform