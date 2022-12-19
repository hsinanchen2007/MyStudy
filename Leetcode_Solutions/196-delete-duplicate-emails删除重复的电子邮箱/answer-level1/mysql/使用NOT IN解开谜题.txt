简单难度也花了不少时间😨
```
DELETE FROM Person
WHERE Id NOT IN (
    SELECT id FROM (
        SELECT MIN(Id) AS Id FROM Person
        GROUP BY Email
    ) t
)
```
