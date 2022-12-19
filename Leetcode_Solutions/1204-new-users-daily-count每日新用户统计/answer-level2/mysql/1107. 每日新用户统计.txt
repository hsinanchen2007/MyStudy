### 解题思路
此处撰写解题思路
1.先统计出每个用户的首次登陆的日期
2.按照日期对用户进行计数
3.筛选出90天内的日期
### 代码

```mysql
# Write your MySQL query statement below

select t.activity_date as login_date ,count(*) as user_count  
from (
    select a.user_id as user_id,min(a.activity_date) as activity_date
    from Traffic a
    where a.activity ="login"
    group by a.user_id
)t
where datediff('2019-06-30',t.activity_date) <=90
group by t.activity_date

```