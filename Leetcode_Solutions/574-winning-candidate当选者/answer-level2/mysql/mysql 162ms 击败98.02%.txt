```
select name 
from (
select name,count(*) freq
from vote v left join candidate c on v.candidateid = c.id
group by candidateid
) e
order by freq desc
limit 1

```
