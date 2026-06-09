### 解题思路
1.分别求出未被封禁的订单数和取消出行的订单数,以日期分组
2.按题目给出的公式计算
注:要注意一下时间范围,只能2013-10-01到2013-10-03

### 代码

```mysql
# Write your MySQL query statement below

SELECT
	tmp3.Request_at AS Day,
	ifnull ( round( tmp2.cancount / tmp1.ccount, 2 ), 0.00 ) AS 'Cancellation Rate' 
FROM
	( SELECT DISTINCT t.Request_at FROM Trips t ) tmp3
	LEFT JOIN (
	SELECT
		t.Request_at,
		count( t.Request_at ) ccount 
	FROM
		Trips t
		LEFT JOIN Users u ON u.Users_Id = t.Client_Id 
	WHERE
		u.Banned = 'No' 
	GROUP BY
		t.Request_at 
	) tmp1 ON tmp3.Request_at = tmp1.Request_at
	LEFT JOIN (
	SELECT
		t.Request_at,
		count( t.Request_at ) cancount 
	FROM
		Trips t
		JOIN Users u ON u.Users_Id = t.Client_Id 
	WHERE
		u.Banned = 'No' 
		AND ( t.Status = 'cancelled_by_client' OR t.Status = 'cancelled_by_driver' ) 
	GROUP BY
		t.Request_at 
	) tmp2 ON tmp3.Request_at = tmp2.Request_at 
WHERE
	tmp3.Request_at <= '2013-10-03' 
	AND tmp3.Request_at >= '2013-10-01' 
ORDER BY
	tmp3.Request_at ASC;

# 查询状态正常的用户订单数,日期分组
# select t.Request_at,count(t.Request_at) ccount from Trips t left join Users u on u.Users_Id = t.Client_Id where  u.Banned = 'No' group by t.Request_at

# 查询状态正常的取消订单数,日期分组
# select t.Request_at,count(t.Request_at) cancount from Trips t join Users u on u.Users_Id = t.Client_Id where  u.Banned = 'No' and (t.Status = 'cancelled_by_client' or t.Status = 'cancelled_by_driver') group by t.Request_at

#ifnull ( round( tmp2.cancount / tmp1.ccount, 2 ), 0.00 )
#ifnull如果为空,则返回0.00;
#round(num,scale),四舍五入,保留两位小数
```