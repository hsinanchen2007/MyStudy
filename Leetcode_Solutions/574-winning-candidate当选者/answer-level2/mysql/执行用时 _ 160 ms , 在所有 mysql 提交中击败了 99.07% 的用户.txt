SELECT Name FROM Candidate
WHERE Id = (
    SELECT CandidateId 
    FROM Vote 
    GROUP BY CandidateId
    ORDER BY COUNT(id) desc
    LIMIT 1
)