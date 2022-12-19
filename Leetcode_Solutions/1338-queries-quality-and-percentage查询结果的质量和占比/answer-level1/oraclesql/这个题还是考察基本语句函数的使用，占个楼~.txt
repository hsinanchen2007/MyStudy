#怪我英文垃圾箩~
```
/* Write your PL/SQL query statement below */
SELECT a.query_name, round(a.qualitySum / count, 2) AS quality
	, round(a.poor_query_percentageSum / count * 100, 2) AS poor_query_percentage
FROM (
	SELECT query_name, COUNT(*) AS count
		, SUM(rating / position) AS qualitySum
		, SUM(CASE 
			WHEN rating < 3 THEN 1
			ELSE 0
		END) AS poor_query_percentageSum
	FROM Queries
	GROUP BY query_name
) a
```
