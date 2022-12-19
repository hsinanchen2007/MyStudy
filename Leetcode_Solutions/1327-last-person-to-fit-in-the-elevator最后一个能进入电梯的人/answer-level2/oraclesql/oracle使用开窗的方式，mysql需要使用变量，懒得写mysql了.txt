```
/* Write your PL/SQL query statement below */
SELECT person_name
FROM Queue a
WHERE a.turn = (
	SELECT MAX(turn)
	FROM (
		SELECT a.turn, a.person_name, SUM(weight) OVER (ORDER BY turn) AS eleWeight
		FROM Queue a
	) a
	WHERE a.eleWeight <= 1000
)

```
