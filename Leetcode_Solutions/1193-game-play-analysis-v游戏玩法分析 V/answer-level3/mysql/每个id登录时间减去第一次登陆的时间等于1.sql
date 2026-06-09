每个id登录时间减去第一次登陆的时间等于1记为1否则0

select  ab.event_date install_dt,
        count(distinct(ab.player_id)) installs,
        round(sum(gap)/count(distinct(ab.player_id)),2) Day1_retention
    from 
        (select b.player_id player_id,b.mint event_date,if(datediff(a.event_date,b.mint)=1,1,0) gap from activity a,
        (select player_id, min(event_date) mint from activity group by player_id) b 
    where a.player_id=b.player_id) ab
    group by ab.event_date