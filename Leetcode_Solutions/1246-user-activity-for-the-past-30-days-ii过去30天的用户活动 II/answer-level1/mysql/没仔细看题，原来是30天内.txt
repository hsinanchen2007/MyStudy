### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
#group by 不能跟where得跟having
select ifnull(round(avg(num),2),0) as  average_sessions_per_user
from 
    (
    select count(session_id) as num from 
        (select distinct user_id,session_id from Activity where activity_date> '2019-06-27' ) t
    group by user_id 
    ) t2
```