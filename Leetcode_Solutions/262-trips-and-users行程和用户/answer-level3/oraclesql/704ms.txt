### 解题思路
使用Exists排除禁止用户 ， DECOD效率要比CASE WHEN 好一点

### 代码

```oraclesql

SELECT Request_At AS "Day" , ROUND(CNT/TOTAL,2) AS "Cancellation Rate" FROM ( 
SELECT T.Request_At , SUM(DECODE(STATUS , 'completed', 0 , 1)) AS CNT , COUNT(*) AS TOTAL  FROM Trips T 
WHERE EXISTS ( SELECT  1 FROM  users T1 
WHERE T.Client_Id = T1.USERS_ID
AND T1.Banned = 'No'
AND T1.ROLE = 'client' )
AND EXISTS ( SELECT  1 FROM  users T1 
WHERE T.Driver_Id = T1.USERS_ID
AND T1.Banned = 'No'
AND T1.ROLE = 'driver' )
AND EXISTS ( SELECT  1 FROM  users T1 
WHERE T.Driver_Id = T1.USERS_ID
AND T1.Banned = 'No'
AND T1.ROLE = 'driver' )
and T.Request_At >= '2013-10-01' 
and T.Request_At <= '2013-10-03'
GROUP BY T.Request_At )
ORDER BY Request_At



```