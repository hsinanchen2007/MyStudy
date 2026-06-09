```
select p1.Name from Vote p2 left join Candidate p1
on p1.id = p2.CandidateId
group by p2.CandidateId
order by count(p2.CandidateId) desc
limit 1 offset 0
```
