select distinct num  as ConsecutiveNums from (
select
    id,
    num,
    lag(num) over(order by id) as lag,
    lead(num) over(order by id) as lead
from
    Logs   
) where num = lag and num = lead 