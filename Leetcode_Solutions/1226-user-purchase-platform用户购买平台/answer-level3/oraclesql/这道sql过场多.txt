#就是全面这个union 是真的恶心,大佬帮我改改，谢了
```
/* Write your PL/SQL query statement below */
SELECT to_char(a.spend_date,'yyyy-MM-dd') as spend_date, a.platform
	, CASE 
		WHEN b.total_amount IS NOT NULL THEN b.total_amount
		ELSE 0
	END AS total_amount
	, CASE 
		WHEN b.total_users IS NOT NULL THEN b.total_users
		ELSE 0
	END AS total_users
FROM (
	SELECT spend_date, platform
	FROM (
		SELECT 'desktop' AS platform
		FROM dual
		UNION
		SELECT 'mobile' AS platform
		FROM dual
		UNION
		SELECT 'both' AS platform
		FROM dual
	) a
		cross join (
			SELECT DISTINCT spend_date
			FROM Spending
		) b
) a
	LEFT JOIN (
		SELECT spend_date, platform, SUM(amount) AS total_amount
			, COUNT(*) AS total_users
		FROM (
			SELECT user_id, spend_date, SUM(amount) AS amount
				, CASE 
					WHEN COUNT(*) >= 2 THEN 'both'
					ELSE MAX(platform)
				END AS platform
			FROM Spending
			GROUP BY user_id, spend_date
		) a
		GROUP BY spend_date, platform
	) b
	ON a.spend_date = b.spend_date
		AND a.platform = b.platform
```
