### 解题思路
t2：日期和平台排序
t3:计算用户数量和amount
592 ms,效率不是很高
### 代码

```mysql
# Write your MySQL query statement below
#日期排序要按照给定的日期顺序
#平台自定义排序
select  t2.*,ifnull(t3.total_amount,0) as total_amount,ifnull(t3.total_users,0)  as total_users 
from 
        ( select * from 
                (select distinct spend_date from Spending) s1 
                join
                 (select * from
                    (select distinct platform from Spending
                     union (select @platform :="both"))tt 
                    ORDER  BY  FIELD( platform,  'desktop',   'mobile',   'both') 
                ) s2
         ) t2
left join 
        (
            select  spend_date ,platform,count(user_id) as total_users ,sum(amount2) as total_amount
            from
                (
                    select spend_date,if(count(*)=2,'both',platform) as platform,user_id ,
                        if(count(*)=2,sum(amount),amount) as amount2 
                    from Spending 
                    group by spend_date,user_id
                )t 
            group by spend_date,platform
        )t3
on t2.spend_date = t3.spend_date and t2.platform = t3.platform 



```