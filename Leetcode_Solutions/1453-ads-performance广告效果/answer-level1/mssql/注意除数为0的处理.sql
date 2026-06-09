主要注意 除数是 0 的处理
```
SELECT ad_id
	, convert(decimal(10, 2), isnull(SUM(CASE 
		WHEN action = 'Clicked' THEN 1
		ELSE 0
	END) * 100.0 / nullif(SUM(CASE 
		WHEN action <> 'Ignored' THEN 1
		ELSE 0
	END), 0), 0)) AS ctr
FROM Ads
GROUP BY ad_id
ORDER BY ctr DESC, ad_id ASC
```
