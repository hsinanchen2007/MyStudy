
感觉需要注意的有两个方面：一是去重，可以直接通过搜索Client_Id，Driver_Id的取值范围，
另一个就是变量命名问题，这里，名字大小写不一样都都算错，可以用“”封起来

```
SELECT  
Request_at as "Day", 
ROUND(CAN_NUM/TOTAL,2) as "Cancellation Rate"
FROM
(SELECT Request_at,
SUM(CASE WHEN Status != 'completed' THEN 1 ELSE 0 END) CAN_NUM,
COUNT(1) TOTAL
FROM Trips T
WHERE T.Client_Id  IN (SELECT Users_Id FROM Users WHERE Banned='No' )
 AND T.Driver_Id  IN (SELECT Users_Id FROM Users WHERE Banned='No' )
AND  T.Request_at IN ('2013-10-01','2013-10-02','2013-10-03')
GROUP BY Request_at)
order by Request_at;
```
