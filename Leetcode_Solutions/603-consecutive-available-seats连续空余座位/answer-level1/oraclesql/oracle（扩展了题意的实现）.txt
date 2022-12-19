为了需求可能存在的扩展，所有我采用了我体育馆那道题的思维方式，动态连续日期可以进行变化，也算自己在此类问题的通用解决思路吧
```
SELECT DISTINCT b.seat_id
FROM (
	SELECT *
	FROM (
		SELECT a.*, LEAD(rownum, 1) OVER (ORDER BY rownum) AS nextNumId, rownum AS numId
		FROM cinema a
	) a
	WHERE a.nextNumId IS NOT NULL
		AND 0 = (
			SELECT COUNT(*)
			FROM (
				SELECT c.*, rownum AS numId
				FROM cinema c
			) b
			WHERE b.numId >= a.numId
				AND b.numId <= a.nextNumId
				AND b.free = 0
		)
) a
	JOIN (
		SELECT b.*, rownum AS rownumId
		FROM cinema b
	) b ON b.rownumId >= a.numId
AND b.rownumId <= a.nextNumId 
ORDER BY seat_id
```
