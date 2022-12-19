```
select  
   t.team_id ,
   t.team_name,
   ifnull(sum(totals) ,0)as num_points    
    
from(
        select
            host_team,
            sum(
                case when host_goals  > guest_goals   then 3
                    when host_goals  =   guest_goals then 1
                    when host_goals  < guest_goals then 0 
                    end 
            ) as totals
        from Matches 
        group by host_team
        union all 
        select
            guest_team ,
            sum(
                case when guest_goals  > host_goals   then 3
                    when guest_goals  =   host_goals then 1
                    when guest_goals  < host_goals then 0 
                    end 
            ) as totals
        from Matches 
        group by guest_team 
) as a 
right join Teams t on t.team_id=a.host_team
group by t.team_id
order by num_points desc,team_id 
```
