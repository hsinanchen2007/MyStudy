过程都写到注释里了

```sql
# 每组最高得分，关联每个player 的得分，按 group_id 聚合，取出各组符合最高得分的最小 player_id
select t1.group_id, min(t1.player_id) as player_id
from (
         # 算出每个 player 的得分
         select t1.player_id, t2.group_id, sum(score) as score
         from (
                  select first_player as player_id, first_score as score
                  from Matches t1
                  union all
                  select second_player as player, second_score as score
                  from Matches t2
              ) t1,
              Players t2
         where t1.player_id = t2.player_id
         group by 1, 2
     ) t1,
     (
         # 算出每组的最高得分
         select group_id, max(score) as max_score
         from (
                  # 再算一次每个 player 的得分
                  select t1.player_id, t2.group_id, sum(score) as score
                  from (
                           select first_player as player_id, first_score as score
                           from Matches t1
                           union all
                           select second_player as player, second_score as score
                           from Matches t2
                       ) t1,
                       Players t2
                  where t1.player_id = t2.player_id
                  group by 1, 2
              ) t1
         group by group_id
     ) t2
where t1.group_id = t2.group_id
and t1.score = t2.max_score
group by t1.group_id
```