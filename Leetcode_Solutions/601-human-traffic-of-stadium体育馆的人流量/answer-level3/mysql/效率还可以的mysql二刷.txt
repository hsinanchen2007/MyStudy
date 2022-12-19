#总结一点：多刷题了之后再回来刷题，思路和以前的oracle解法发生了很大的变化
```
SELECT a.id, a.visit_date, a.people
FROM (
	SELECT a.*, a.id - @rk AS groupId, @rk := @rk + 1
	FROM stadium a, (
			SELECT @rk := 1
		) s
	WHERE a.people >= 100
) a
WHERE a.groupId IN (
	SELECT b.groupId
	FROM (
        SELECT b.*, b.id - @rk2 AS groupId, @rk2 := @rk2 + 1
        FROM stadium b, (
                SELECT @rk2 := 1
            ) s
        WHERE b.people >= 100
	) b
	GROUP BY b.groupId
	HAVING COUNT(b.groupId) >= 3
)
```
