### 解题思路
此处撰写解题思路
先弄每个人得分表，然后连接到组，个人分数，名字，然后自连接找每一组的赢家，菜鸟写的太离谱了
### 代码

```mysql
# Write your MySQL query statement below
#select matches.match_id,matches.first_player,matches.second_player,matches.first_score,matches.second_score,p1.group_id first_group,p2.group_id second_group from matches join
#(players p1 join players p2 ) on matches.first_player=p1.player_id and matches.second_player=p2.player_id 
#select if(first_score>second_score,first_player,if(first_score=second_score,if(first_player<second_player,first_player,second_player),second_player)) winner from matches
select group_id,min(player_id) player_id from 
(select a1.group_id,a1.player_id from 
(select players.player_id,players.group_id,q.score from players left join
    (select first_player,sum(first_score) score from
        (select first_player,first_score from matches
        union all
        select second_player,second_score from matches)  t
    group by t.first_player) q
    on players.player_id=q.first_player ) a1
left join 
(select players.player_id,players.group_id,q.score from players left join
(select first_player,sum(first_score) score from
(select first_player,first_score from matches
union all
select second_player,second_score from matches) t
group by t.first_player) q
on players.player_id=q.first_player ) a2 on a1.player_id!=a2.player_id and a1.group_id=a2.group_id and a1.score<a2.score where a2.score is null and a1.score!=0) wd group by group_id
```