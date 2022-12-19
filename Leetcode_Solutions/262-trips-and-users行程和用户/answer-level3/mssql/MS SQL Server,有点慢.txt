```
select c.Day,
ISNULL(CONVERT(DECIMAL(18,2),NULLIF(CAST(cancell_cnt as DECIMAL(18,3)),0) /NULLIF(cnt,0)), 0) AS 'Cancellation Rate'
 from
(select Request_at as Day,count(1) cnt from Trips a
INNER JOIN Users b on a.Client_Id=b.Users_Id  and b.Banned='No' AND Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Request_at) as c
LEFT  JOIN
(select Request_at as Day,count(1) cancell_cnt from Trips a
INNER JOIN Users b on a.Client_Id=b.Users_Id  and b.Banned='No'  and  Status<>'completed' AND Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Request_at) as d
ON c.Day=d.Day
```
