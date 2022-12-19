
```
SELECT s.id, isnull(ss.student, s.student) AS student
FROM seat s
	LEFT JOIN seat ss
	ON abs(s.id - ss.id) = 1
		AND ((s.id % 2 = 0
				AND s.id > ss.id)
			OR (s.id % 2 = 1
				AND s.id < ss.id))
ORDER BY id
```
