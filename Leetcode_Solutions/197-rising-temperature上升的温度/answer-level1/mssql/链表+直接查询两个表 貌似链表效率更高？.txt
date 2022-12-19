链表方式：
SELECT b.ID FROM Weather a INNER JOIN Weather b ON a.RecordDate = DATEADD(DAY,-1,b.RecordDate)
WHERE b.Temperature > a.Temperature
直接查询方式：
SELECT b.ID FROM Weather a ,Weather b
WHERE a.Temperature<b.Temperature AND DATEDIFF(DAY,a.RecordDate,b.RecordDate) = 1