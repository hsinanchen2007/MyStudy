select t1.team_id,t1.team_name,ifnull(r2.num_points,0) as num_points
 from Teams t1 
   left join (
      select r1.id ,sum(r1.goals) as num_points 
      from (
          select host_team  as id ,
            if(host_goals>guest_goals,3,if(host_goals=guest_goals,1,0))as goals
          from Matches
union all 
          select guest_team as id ,
           if(guest_goals>host_goals,3,if(host_goals=guest_goals,1,0)) as goals
          from Matches) as r1 group by r1.id ) as r2 
   on t1.team_id =r2.id order by num_points desc ,t1.team_id 