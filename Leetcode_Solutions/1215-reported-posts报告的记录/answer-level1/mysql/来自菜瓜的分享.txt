### 解题思路
report_count数不对：
原因1：日期
今天是 2019-07-05， 求昨天的  
如果是：dateDiff(d1,d2)=-1，是d1小d2大的情况   
所以有：dateDiff(action_date ,'2019-07-05')=-1
原因2：同一日多次提交
post_id=4的，他report了两次，需要去重count(distinct post_id)

### 代码

```mysql
# Write your MySQL query statement below

select extra as report_reason ,count(distinct post_id) as report_count 
from Actions
where action='report' and dateDiff(action_date ,'2019-07-05')=-1
group by extra

```

### 考虑非空问题代码
```mysql
# Write your MySQL query statement below

select extra as report_reason ,count(distinct post_id) as report_count 
from Actions
where action='report' and dateDiff(action_date ,'2019-07-05')=-1 and extra <> ''
group by extra

```