```
select t3.name Name

from Candidate t3,

(select t1.CandidateId CandidateId

from Vote t1

group by t1.CandidateId

order by count(*) desc

limit 1)t2

where t3.id=t2.CandidateId