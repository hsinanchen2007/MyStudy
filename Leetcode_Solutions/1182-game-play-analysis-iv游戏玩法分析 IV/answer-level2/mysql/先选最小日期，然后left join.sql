### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
-- select 
--     count(case when innerq.games_played is not NUll then 1 else Null end)/count(1) as fraction
--     from
-- ((select player_id, min(event_date) as event_date from Activity group by 1) as lhs
-- left join
-- Activity as A2
-- on
-- lhs.event_date = A2.event_date - 1) as innerq

-- select *
-- from ((select player_id, min(event_date) as date1 from Activity group by 1) as lhs
-- left join
-- Activity as A2
-- on
-- (lhs.date1 = A2.event_date - 1) and (lhs.player_id=A2.player_id)) as innerq

select 
    round(count(case when A2.games_played is not NUll then 1 else Null end)/count(1), 2) as fraction
from
(select player_id, min(event_date) as date1 from Activity group by 1) as lhs
left join
Activity as A2
on
lhs.player_id=A2.player_id and lhs.date1 = A2.event_date - 1

```