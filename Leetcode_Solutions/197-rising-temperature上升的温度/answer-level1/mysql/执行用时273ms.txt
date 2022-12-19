select a.Id
from Weather a left join Weather b
on datediff(a.RecordDate,b.RecordDate)=1
where a.Temperature>b.Temperature