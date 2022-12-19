select
    query_name,
    round(avg(rating/position), 2) as quality ,
    round( (count(if(rating<3, True, null)) / count(query_name)) *100 , 2) as poor_query_percentage 
from
    Queries    
group by query_name