题目中写死了是2018-2020年，那么很简单，我们可以制造一个时间序列来辅助解题，
根据题意，我设置了三个字段：年，年开始时间，年结束时间：
```
				SELECT
					'2018' AS year1,
					'2018-01-01' AS first_date,
					'2018-12-31' AS last_date 
				FROM
				DUAL UNION
				SELECT
					'2019' AS year1,
					'2019-01-01' AS first_date,
					'2019-12-31' AS last_date 
				FROM
				DUAL UNION
				SELECT
					'2020' AS year1,
					'2020-01-01' AS first_date,
					'2020-12-31' AS last_date 
				FROM
				DUAL 
```

接下来要销售对应的年份都列出来（包括整年直接包含的），需要注意，这里是用时间序列的年跟开始时间，结束时间匹配，时间序列年>=开始时间年 and 时间序列年 <=结束时间年。

这样就能得到所有的年份了（连带有开始时间和结束时间）。

我们可以直接用case when 语句来直接计算总的销售额度。
这里要注意，年开始时间、年结束时间、销售开始时间、销售结束时间总共有4种匹配关系，分别判断即可。

另外注意datediff需要+1，最后在匹配上产品名称就可以了。

```
SELECT
	sales.product_id,
	product.product_name,
	dt.year1 AS report_year,
CASE
		
		WHEN sales.period_start >= dt.first_date 
		AND sales.period_end <= dt.last_date THEN
			sales.average_daily_sales * ( DATEDIFF( sales.period_end, sales.period_start ) + 1 ) 
			WHEN sales.period_start >= dt.first_date 
			AND sales.period_end >= dt.last_date THEN
				sales.average_daily_sales * ( DATEDIFF( dt.last_date, sales.period_start ) + 1 ) 
				WHEN sales.period_start <= dt.first_date AND sales.period_end >= dt.last_date THEN
				sales.average_daily_sales * ( DATEDIFF( dt.last_date, dt.first_date ) + 1 ) 
				WHEN sales.period_start <= dt.first_date 
				AND sales.period_end <= dt.last_date THEN
					sales.average_daily_sales * ( DATEDIFF( sales.period_end, dt.first_date ) + 1 ) 
					END AS total_amount 
			FROM
				sales
				RIGHT JOIN (
				SELECT
					'2018' AS year1,
					'2018-01-01' AS first_date,
					'2018-12-31' AS last_date 
				FROM
				DUAL UNION
				SELECT
					'2019' AS year1,
					'2019-01-01' AS first_date,
					'2019-12-31' AS last_date 
				FROM
				DUAL UNION
				SELECT
					'2020' AS year1,
					'2020-01-01' AS first_date,
					'2020-12-31' AS last_date 
				FROM
				DUAL 
				) dt ON dt.year1 >= YEAR ( sales.period_start ) 
			AND dt.year1 <= YEAR ( sales.period_end )
	JOIN Product ON sales.product_id = product.product_id
```

