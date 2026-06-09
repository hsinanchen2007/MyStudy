select query_name,Round(avg(rating/position),2) quality,
Round(sum(if(rating<3,1,0))*100/count(*),2)poor_query_percentage
from Queries
group by query_name