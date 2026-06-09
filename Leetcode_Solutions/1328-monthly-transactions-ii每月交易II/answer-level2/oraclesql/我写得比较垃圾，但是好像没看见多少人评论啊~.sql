###最后的非零判断是真的骚气
```
/* Write your PL/SQL query statement below */
SELECT *
FROM (
	SELECT a.trans_date AS month, a.country, SUM(approved_count) AS approved_count
		, SUM(approved_amount) AS approved_amount, SUM(chargeback_count) AS chargeback_count
		, SUM(chargeback_amount) AS chargeback_amount
	FROM (
		SELECT country, to_char(trans_date, 'yyyy-MM') AS trans_date
			, COUNT(CASE 
				WHEN state = 'approved' THEN 1
				ELSE NULL
			END) AS approved_count, SUM(CASE 
				WHEN state = 'approved' THEN amount
				ELSE 0
			END) AS approved_amount
			, 0 AS chargeback_count, 0 AS chargeback_amount
		FROM Transactions a
		GROUP BY country, to_char(trans_date, 'yyyy-MM')
		UNION ALL
		SELECT b.country, to_char(a.trans_date, 'yyyy-MM') AS trans_date, 0 AS approved_count
			, 0 AS approved_amount, COUNT(*) AS chargeback_count, SUM(b.amount) AS chargeback_amount
		FROM Chargebacks a
			LEFT JOIN Transactions b ON b.id = a.trans_id
		GROUP BY b.country, to_char(a.trans_date, 'yyyy-MM')
	) a
	GROUP BY a.country, a.trans_date
) a
WHERE not(a.approved_count = 0
	AND a.approved_amount = 0
	AND a.chargeback_count = 0
	AND a.chargeback_amount = 0)
```
