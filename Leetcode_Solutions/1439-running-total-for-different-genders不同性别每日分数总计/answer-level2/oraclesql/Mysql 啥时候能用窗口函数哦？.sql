```
select t.gender,
        TO_CHAR(t.day,'YYYY-mm-dd') day,sum(t.total) over (partition by gender order by day) as total 
from
    (select gender,day,sum(score_points) as total from Scores
    group by gender,day
    order by gender,day)t 

```
