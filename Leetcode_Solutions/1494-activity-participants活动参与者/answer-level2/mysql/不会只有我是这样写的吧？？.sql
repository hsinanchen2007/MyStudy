select activity from Friends 
        group by activity having count(*) not in 
             (select max(r1.num) from (  select activity ,count(*) as num from  Friends group by activity ) as r1
             union
             select min(r1.num) from (  select activity ,count(*) as num from  Friends group by activity ) as r1 )