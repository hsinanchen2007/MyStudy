select e1.business_id 
from Events e1 ,(select e.event_type ,avg(e.occurences) as avg  from Events e group by e.event_type) e2 
where e1.event_type =e2.event_type and e1.occurences > e2.avg 
group by e1.business_id 
having count(*)>=2
