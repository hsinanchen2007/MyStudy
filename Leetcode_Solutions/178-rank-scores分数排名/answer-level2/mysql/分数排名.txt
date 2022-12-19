
```
SELECT
	s.Score, t1.rank 
FROM
	Scores s LEFT JOIN (
	SELECT
		Score, @rank := @rank + 1 AS rank 
	FROM
		( SELECT Score FROM Scores GROUP BY Score ORDER BY Score DESC ) r,( SELECT @rank := 0 ) t 
	) t1 ON s.Score = t1.Score 
ORDER BY	Score DESC;
```
