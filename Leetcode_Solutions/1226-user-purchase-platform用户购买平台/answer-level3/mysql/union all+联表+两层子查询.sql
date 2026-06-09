### 解题思路
难点就在于both类
### 代码

```mysql
# Write your MySQL query statement below

select t.spend_date,t.platform,ifnull(t3.total_amount,0) as total_amount ,ifnull(t3.total_users,0) as total_users from
(select distinct spend_date,'both' as platform from Spending 
union all 
select distinct spend_date,'mobile' as platform from Spending
union all
select distinct spend_date,'desktop' as platform from Spending)
t left join 
(select spend_date,platform,sum(amount) as `total_amount`,count(*) as `total_users` from (
    select spend_date,user_id,sum(amount) `amount`,
case when count(distinct platform) > 1 then 'both'
else platform end as platform
from Spending group by spend_date,user_id
) t2 group by spend_date,platform
) t3 on t.spend_date = t3.spend_date and t.platform = t3.platform
```