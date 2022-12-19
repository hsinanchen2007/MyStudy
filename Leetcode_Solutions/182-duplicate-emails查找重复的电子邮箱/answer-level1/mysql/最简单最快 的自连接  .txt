最简单最快
的自连接

```
SELECT DISTINCT
	a.Email as Email
FROM
	person AS a,
	person AS b 
WHERE
	a.Id < b.Id 
	AND a.Email = b.Email;
```
