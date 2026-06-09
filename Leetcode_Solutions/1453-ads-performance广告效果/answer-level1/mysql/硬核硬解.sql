### 解题思路
硬核硬解 记录一下
### 代码

```mysql
# Write your MySQL query statement below

select * from 
(select ad_id,
ifnull(round(sum(case when `action` = 'Clicked' then 1 else 0 end)/
sum(case when `action` = 'Clicked' then 1 else 
case when `action` = 'Viewed' then 1 else 0 end end )*100,2),0.00) as ctr   
 from Ads group by ad_id) d order by ctr desc,ad_id asc
```