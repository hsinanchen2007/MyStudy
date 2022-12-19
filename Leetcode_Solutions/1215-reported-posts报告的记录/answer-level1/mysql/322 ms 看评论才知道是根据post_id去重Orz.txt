### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select 
    extra as report_reason,
    count(extra) as report_count
from (select distinct post_id,action,extra from Actions
         where action_date ='2019-07-04'  and extra is not null
         and     action ='report'
    )t

group by  extra
```