```sql
/* Write your T-SQL query statement below */
IF (SELECT MAX(id) FROM seat) % 2 = 0
BEGIN
    SELECT CASE id % 2 WHEN 1 THEN id + 1 WHEN 0 THEN id - 1 END AS id, student
    FROM seat
    ORDER BY id;
END
ELSE
BEGIN
    SELECT CASE id
            WHEN (SELECT MAX(id) FROM seat) then id
            ELSE (CASE id % 2 WHEN 1 THEN id + 1 WHEN 0 THEN id - 1 END)
            END
            AS id, student
    FROM seat
    ORDER BY id;
END
```
