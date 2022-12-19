select C.Name
from Candidate C
where C.id=(select CandidateId from Vote group by CandidateId order by count(id) desc limit 1)