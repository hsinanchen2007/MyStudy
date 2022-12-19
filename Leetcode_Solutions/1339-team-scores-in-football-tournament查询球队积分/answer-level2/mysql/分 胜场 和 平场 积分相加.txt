
select t1.team_id , t1.team_name 
, sum( if(((t1.team_id = t2.host_team and t2.host_goals > t2.guest_goals) 
        or (t1.team_id = t2.guest_team and t2.guest_goals > t2.host_goals)
        ) ,3,0)) +  sum(if(t2.guest_goals = t2.host_goals,1,0))  as num_points    
from Teams t1 
left join     
Matches  t2   
on t1.team_id  =  t2.host_team   or t1.team_id  =  t2.guest_team  
group by t1.team_id , t1.team_name 
order by num_points desc ,team_id asc;
