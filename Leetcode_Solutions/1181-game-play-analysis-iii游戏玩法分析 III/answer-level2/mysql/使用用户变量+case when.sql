1使用CASE WHEN做判断，如果player_id一致则累加，否则重新开始赋值
2CAST (expression AS SIGNED)转化成整型

SELECT
    player_id
    ,event_date
    ,CAST((CASE WHEN @prev=player_id THEN @num:=@num+games_played
                WHEN @prev:=player_id THEN @num:=games_played 
            END) 
     AS SIGNED) AS games_played_so_far
FROM 
    Activity
    ,(SELECT @num:=0,@prev:=null) t
ORDER BY
    player_id,event_date
;