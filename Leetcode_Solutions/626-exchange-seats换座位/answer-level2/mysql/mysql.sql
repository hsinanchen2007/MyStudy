```
SELECT 
    (CASE 
        WHEN id % 2 = 0 THEN id - 1
        WHEN id % 2 != 0 AND id != (SELECT max(id) FROM seat) THEN id + 1 ELSE id
    END) AS id, student
FROM seat
ORDER BY id
```
