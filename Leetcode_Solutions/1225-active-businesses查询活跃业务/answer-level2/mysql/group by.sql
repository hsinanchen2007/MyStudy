select  events.business_id 
from events,
(select event_type,avg(occurences) asum from events group by event_type) a 
where events.event_type=a.event_type
group by events.business_id
having sum(if(events.occurences>a.asum,1,0))>=2
