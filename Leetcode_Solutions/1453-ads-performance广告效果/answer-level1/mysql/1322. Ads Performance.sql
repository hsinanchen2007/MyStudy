### 解题思路
其实 ctr分为两种情况，就是说分母为0时直接取0，不为0时用公式计算。只需要使用条件句区分开就行

### 代码

```mysql
# Write your MySQL query statement below

select ad_id,
	case when (sum(case when action = 'Clicked' then 1 else 0 end) + sum(case when action = 'viewed' then 1 else 0 end)) = 0 then 0 
    else
	round((sum(case when action = 'Clicked' then 1 else 0 end) * 100/ (sum(case when action = 'Clicked' then 1 else 0 end) + sum(case when action = 'viewed' then 1 else 0 end))),2) 
    end as ctr  
from Ads
group by ad_id 
order by ctr desc, ad_id asc;
```