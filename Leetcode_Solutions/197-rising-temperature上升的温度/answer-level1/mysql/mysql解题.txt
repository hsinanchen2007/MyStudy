DATEDIFF(expr1,expr2)：是expr1 - expr2 
前面是tw.temperature > w.temperature，所以DATEDIFF()时，tw要放前面。
```
SELECT
	tw.id 
FROM
	weather w
	JOIN weather tw ON tw.temperature > w.temperature AND DATEDIFF( tw.recordDate, w.recordDate ) = 1;
```
