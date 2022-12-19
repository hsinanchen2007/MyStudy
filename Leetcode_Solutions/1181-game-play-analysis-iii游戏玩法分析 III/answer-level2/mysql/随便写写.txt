### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select A1.player_id, A1.event_date, sum(A2.games_played) as games_played_so_far
from
Activity as A1
left join
Activity as A2
on A1.player_id = A2.player_id and 
   A1.event_date >= A2.event_date
group by 1,2
order by 1,2
```