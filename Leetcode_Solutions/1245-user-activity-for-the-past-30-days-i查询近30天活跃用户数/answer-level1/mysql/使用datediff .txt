### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select  t.`activity_date` as `day` , count( distinct t.user_id) as active_users 
from Activity t
group by t.`activity_date`
having Datediff('2019-07-27',t.activity_date) <30 and Datediff('2019-07-27',t.activity_date) >=0
```