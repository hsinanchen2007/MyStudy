select distinct num as ConsecutiveNums
from
(select id,num,
lag(num,1,null) over(order by id) as num_1,
lag(num,2,null) over(order by id) as num_2 
from logs)t1
where num=num_1 and num=num_2