```
SELECT CASE 
		WHEN COUNT(*) = 2 THEN SUM(f.Number) / 2
		ELSE f.Number
	END AS median
FROM (
	SELECT CEIL(SUM(Frequency) / 2) AS midIndex
		, CASE 
			WHEN SUM(Frequency) % 2 = 0 THEN 1
			ELSE 0
		END AS needPlus
	FROM Numbers
) e
	JOIN (
		SELECT c.*,d.Frequency, (rightIndex - Frequency + 1) as leftIndex
		FROM (
			SELECT a.Number, SUM(b.Frequency) AS rightIndex
			FROM Numbers a
				JOIN Numbers b ON a.Number >= b.Number
			GROUP BY Number
		) c
			JOIN Numbers d ON c.Number = d.Number
	) f
	ON (e.midIndex <= f.rightIndex
			AND e.midIndex >= leftIndex)
		OR (e.midIndex + needPlus <= f.rightIndex
			AND e.midIndex + needPlus >= leftIndex)
WHERE f.Frequency > 0
```
