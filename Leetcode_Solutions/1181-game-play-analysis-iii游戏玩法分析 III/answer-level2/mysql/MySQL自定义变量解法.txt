```
select 
player_id,
event_date,
 cast(case when @total = player_id then   @num := @pre:=games_played+@pre  
      when @total := player_id then  @pre:=games_played
      else @pre 
      end 
    as SIGNED)  as games_played_so_far 
from  Activity  a ,(select @num:=0,@pre:=0,@total:=0) b  order by player_id ,event_date 
```
