### 解题思路
1.event_date 和 installs 先求出来
2.event_date 和 retention

关键要考虑的问题是一个人注册日可能是另一个人的返还日，所以如果不用playeridqu对应会算重复
### 代码

```mysql
# Write your MySQL query statement below
select dt install_dt,count(a.player_id) installs,round(count(b.player_id)/count(a.player_id),2) Day1_retention
from
    (
        select player_id,min(event_date) dt
        from activity
        group by player_id
    ) a left join activity b 
        on a.player_id = b.player_id and datediff(b.event_date,a.dt) = 1
group by a.dt





```