开始想了好久，准备分别查只有desktop的,只有mobile的,以及both的,发现查只有desktop的的这个太复杂，
后面换了个思路,先按照spend_date,user_id把只有desktop的,只有mobile的,以及both的全部查出来,
然后再把这个结果按照spend_date分组计算金额以及人数
```
select spend_date,platform, sum(amount) as total_amount, count(user_id) total_users
from
(select spend_date, user_id, 
(case count(distinct platform)
    when 1 then platform
    when 2 then 'both'
    end
) as  platform, sum(amount) as amount
from Spending
group by spend_date, user_id
) as temp2
group by spend_date, platform
```

但是这样得出来的只有某些spend_date某些user_id
的，题目要求是不存在也要放在结果里面,只是结果置0而已。我在网上找到了
这种写法
```
select distinct(spend_date), p.platform   
from Spending,
(select 'desktop' as platform union
 select 'mobile' as platform union
 select 'both' as platform
) as p 
```
这样枚举出来就把结果的前两列查出来了。
然后把这两步的结果合并就可以了。
完整的sql如下：
```
select temp1.spend_date, temp1.platform, 
       ifnull(temp3.total_amount, 0) total_amount, 
       ifnull(temp3.total_users,0) total_users
       from
(select distinct(spend_date), p.platform   
from Spending,
(select 'desktop' as platform union
 select 'mobile' as platform union
 select 'both' as platform
) as p 
) as temp1
left join 
(select spend_date,platform, sum(amount) as total_amount, count(user_id) total_users
from
(select spend_date, user_id, 
(case count(distinct platform)
    when 1 then platform
    when 2 then 'both'
    end
) as  platform, sum(amount) as amount
from Spending
group by spend_date, user_id
) as temp2
group by spend_date, platform
) as  temp3
on temp1.platform = temp3.platform and temp1.spend_date = temp3.spend_date
```

