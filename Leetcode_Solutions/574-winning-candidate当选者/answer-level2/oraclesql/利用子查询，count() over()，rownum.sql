```
select Name
from Candidate
where
id in
(
    select CandidateId
    from
    (
        select CandidateId,
        count(CandidateId) over(partition by CandidateId order by id) cn  -- count(CandidateId)忽略空值
        from Vote
        order by cn desc
    ) v
    where rownum = 1
);
```
