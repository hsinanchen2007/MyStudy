```
SELECT
    S1.id,
    ifnull(S2.student, S1.student) AS student
FROM
    seat S1
    LEFT JOIN
    seat S2
ON
    mod(S1.id,2) = 1 AND S1.id = S2.id - 1
    OR
    mod(S1.id,2) = 0 AND S1.id = S2.id + 1
ORDER BY 
    S1.id;
```