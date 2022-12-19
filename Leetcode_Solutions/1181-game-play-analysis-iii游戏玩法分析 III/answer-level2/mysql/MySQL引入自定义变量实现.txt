# Write your MySQL query statement below



    
    select  player_id, event_date
    
 
        
        , case when @u = player_id then @cum:=@cum+games_played 
          when @u := player_id  then @cum := games_played
        else games_played end games_played_so_far
        
    

    from Activity, (select @rk:=0, @u:= Null , @cum:=0) a

    order by player_id, event_date

    