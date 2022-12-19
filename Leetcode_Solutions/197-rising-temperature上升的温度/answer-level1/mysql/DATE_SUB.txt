``` MySQL
SELECT A.Id  
FROM Weather AS A  
INNER JOIN Weather AS B  
ON B.RecordDate = DATE_SUB(A.RecordDate, interval 1 day)  
AND A.Temperature > B.Temperature
```