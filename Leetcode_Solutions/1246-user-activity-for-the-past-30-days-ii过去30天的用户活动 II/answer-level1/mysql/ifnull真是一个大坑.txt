```
# Write your MySQL query statement below
select ifnull(round(avg(cnt),2),0) as average_sessions_per_user
from (select user_id,count(distinct session_id) as cnt
from Activity
where datediff('2019-07-27',activity_date)<30
group by user_id) tmp
```
题目没有提醒要考虑null的情况，第一次没写ifnull，测试用例可以通过，但是提交显示结果是null。。。