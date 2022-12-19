我犯了一个错，用了如下的语句来判断 是否是最近一年
datediff(year, dispatch_date, '2019-06-23') <= 1
事实上，就算超过一年也可能返回 1，像下面这样，结果就是返回 1
select datediff(year, '2018-04-03', '2019-06-23')
在这个题中我不知道怎么用 datediff 来解决这个问题，欢迎指教。

思路：先找出一年内销量 >=10 的 book_id，那剩下的 就都是 <10 的
```
SELECT book_id, name
FROM Books
WHERE book_id NOT IN (
		SELECT book_id
		FROM Orders
		WHERE dispatch_date>='2018-06-23'
		GROUP BY book_id
		HAVING SUM(quantity) >= 10
	)
	AND  available_from <= '2019-05-23'
```
