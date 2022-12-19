### 解题思路
主要使用round、count、if函数

### 代码

```mysql
SELECT
	request_at 'DAY',
	round( count( IF ( STATUS = 'cancelled_by_driver' OR STATUS = 'cancelled_by_client', TRUE, NULL ) ) / count( a.id ), 2 ) AS 'Cancellation Rate' 
FROM
	trips a,
	users b 
WHERE
	a.client_id = b.users_id 
	AND b.banned = 'No' 
	AND request_at >= '2013-10-01' 
	AND request_at <= '2013-10-03' 
GROUP BY
	request_at
```