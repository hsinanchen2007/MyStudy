### 解题思路
这道题的几个比较迷惑人的地方，首先between and 不包括右边边界，所以要加一。30天之前，不包括第30天，所以要减掉29.

### 代码

```mysql
# Write your MySQL query statement below
select activity_date as day, count(distinct user_id) as active_users
from Activity
where activity_date between DATE_SUB('2019-07-27', INTERVAL 29 DAY) and DATE_ADD('2019-07-27',INTERVAL 1 DAY)
group by activity_date
```