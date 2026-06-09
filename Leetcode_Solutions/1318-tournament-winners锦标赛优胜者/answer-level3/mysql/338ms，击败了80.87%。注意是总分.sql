### 解题思路
调试了半天，发现原来是要计算每个运动员的总分

### 代码

```mysql
# Write your MySQL query statement below
select group_id,player_id from
(
    select t.*,if(@id = group_id,@num:=@num+1,@num:=1) as num,
         if(@id = group_id,group_id,@id := group_id) as id
from
    (select group_id,player_id , score from 
        players
    left join 
        (select player,sum(score) as score from
            (select first_player as player,first_score as score from
            matches 
            union all 
            select second_player as player,second_score as score from
            matches )t
        group by player
        
        )t 
    on players.player_id = t.player
    order by group_id,score desc,player_id)t,
    (select @id:=-1) t1,
    (select @num:=0) t2
    )    t3
where num = 1

    
```