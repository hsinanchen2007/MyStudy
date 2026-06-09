SELECT  player_id,event_date,      
       
      CONVERT(
        CASE 
            WHEN @prev=player_id   THEN  @num:=games_played+@num
            WHEN @prev:=player_id  THEN  @num:=games_played         
        END 
        ,SIGNED
      )        
        AS games_played_so_far
        
FROM (SELECT @num:=0, @prev:=0) temp, Activity 

ORDER BY player_id,event_date