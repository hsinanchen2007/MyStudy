[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

统计每天非禁止用户的取消率，需要知道非禁止用户有哪些，总行程数，取消的行程数。

# 解法一
首先确定被禁止用户的行程记录，再剔除这些行程记录。

行程表中，字段client_id和driver_id，都与用户表中的users_id关联。因此只要client_id和driver_id中有一个被禁止了，此条行程记录要被剔除。

先说一种错误的找出没被禁止用户行程记录的方法。此方法很有迷惑性。

思路：
```
if (client_id = users_id 或 driver_id = users_id) 且 users_id没有被禁止
{
    此条记录没被禁止。
}
```
SQL代码
```
SELECT *
FROM Trips AS T JOIN Users AS U 
ON (T.client_id = U.users_id  OR T.driver_id = U.users_id )  AND U.banned ='No'
```
乍一看，思路是对。其实是错误的。因为，我们不知觉得肯定了一个假设——client_id与driver_id是相同的。只有当两者相同时，才能用此条件排除被禁止用户的行程记录。

错误的结果：
```
+------+-----------+-----------+---------+---------------------+------------+----------+--------+--------+
| Id   | Client_Id | Driver_Id | City_Id | STATUS              | Request_at | Users_Id | Banned | Role   |
+------+-----------+-----------+---------+---------------------+------------+----------+--------+--------+
|    1 |         1 |        10 |       1 | completed           | 2013-10-01 |        1 | No     | client |
|    1 |         1 |        10 |       1 | completed           | 2013-10-01 |       10 | No     | driver |
|    2 |         2 |        11 |       1 | cancelled_by_driver | 2013-10-01 |       11 | No     | driver |
|    3 |         3 |        12 |       6 | completed           | 2013-10-01 |        3 | No     | client |
|    3 |         3 |        12 |       6 | completed           | 2013-10-01 |       12 | No     | driver |
|    4 |         4 |        13 |       6 | cancelled_by_client | 2013-10-01 |        4 | No     | client |
|    4 |         4 |        13 |       6 | cancelled_by_client | 2013-10-01 |       13 | No     | driver |
|    5 |         1 |        10 |       1 | completed           | 2013-10-02 |        1 | No     | client |
|    5 |         1 |        10 |       1 | completed           | 2013-10-02 |       10 | No     | driver |
|    6 |         2 |        11 |       6 | completed           | 2013-10-02 |       11 | No     | driver |
|    7 |         3 |        12 |       6 | completed           | 2013-10-02 |        3 | No     | client |
|    7 |         3 |        12 |       6 | completed           | 2013-10-02 |       12 | No     | driver |
|    8 |         2 |        12 |      12 | completed           | 2013-10-03 |       12 | No     | driver |
|    9 |         3 |        10 |      12 | completed           | 2013-10-03 |        3 | No     | client |
|    9 |         3 |        10 |      12 | completed           | 2013-10-03 |       10 | No     | driver |
|   10 |         4 |        13 |      12 | cancelled_by_driver | 2013-10-03 |        4 | No     | client |
|   10 |         4 |        13 |      12 | cancelled_by_driver | 2013-10-03 |       13 | No     | driver |
+------+-----------+-----------+---------+---------------------+------------+----------+--------+--------+
```
结果中，被禁止的users_id = 2，其行程记录没被剔除掉。

明显， client_id与driver_id不一定相同 。

正确的做法是对client_id和driver_id各自关联的users_id，同时检测是否被禁止。
```
if (client_id = users_id_1 且 users_id_1没被禁止 并且 client_id = users_id_2 且 users_id_2没被禁止){
    此条记录没被禁止。
}
```
SQL代码：
```
SELECT *
FROM Trips AS T
JOIN Users AS U1 ON (T.client_id = U1.users_id AND U1.banned ='No')
JOIN Users AS U2 ON (T.driver_id = U2.users_id AND U2.banned ='No')
```
在此基础上，按日期分组，统计每组的 总行程数，取消的行程数 。

每组的总行程数：COUNT(T.STATUS)。

每组的取消的行程数：
```
SUM(
	IF(T.STATUS = 'completed',0,1)
)
```
取消率 = 每组的取消的行程数 / 每组的总行程数

完整逻辑为:
```
SELECT T.request_at AS `Day`, 
	ROUND(
			SUM(
				IF(T.STATUS = 'completed',0,1)
			)
			/ 
			COUNT(T.STATUS),
			2
	) AS `Cancellation Rate`
FROM Trips AS T
JOIN Users AS U1 ON (T.client_id = U1.users_id AND U1.banned ='No')
JOIN Users AS U2 ON (T.driver_id = U2.users_id AND U2.banned ='No')
WHERE T.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY T.request_at
```
其中SUM求和函数，COUNT计数函数，ROUND四舍五入函数。

# 解法二
思路与解法一相同。而采用不同的方法排除掉被禁止用户的行程记录。想到排除，就联想到集合差。

client_id和driver_id的全部为集合U。被禁止的users_id集合为A。

U减去A的结果为没被禁止的用户。
```
(
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
) AS A
```
好了，先演示一个错误的解法：

行程表连接表A，排除掉被被禁止的行程。
```
SELECT *
FROM trips AS T,
(
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
) AS A
WHERE (T.Client_Id != A.users_id AND T.Driver_Id != A.users_id)
```
剩下的逻辑与解法一后部分相同，完善后的逻辑为：
```
SELECT T.request_at AS `Day`, 
	ROUND(
			SUM(
				IF(T.STATUS = 'completed',0,1)
			)
			/ 
			COUNT(T.STATUS),
			2
	) AS `Cancellation Rate`
FROM trips AS T,
(
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
) AS A
WHERE (T.Client_Id != A.users_id AND T.Driver_Id != A.users_id) AND T.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY T.request_at
```
很可惜，当表A为空时，此方法的结果是空表。但是表A为空，可能是有用户但是没有被禁止的用户。因此方法是错误的。

正确的解法是：行程表left join 表A两次，A.users_id都为NULL的行都是没被排除的行。
```
SELECT *
FROM trips AS T LEFT JOIN 
(
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
) AS A ON (T.Client_Id = A.users_id)
LEFT JOIN (
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
) AS A1
ON (T.Driver_Id = A1.users_id)
WHERE A.users_id IS NULL AND A1.users_id IS NULL
```
补上其它部分的逻辑为：
```
SELECT T.request_at AS `Day`, 
	ROUND(
			SUM(
				IF(T.STATUS = 'completed',0,1)
			)
			/ 
			COUNT(T.STATUS),
			2
	) AS `Cancellation Rate`
FROM trips AS T LEFT JOIN 
(
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
) AS A ON (T.Client_Id = A.users_id)
LEFT JOIN (
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
) AS A1
ON (T.Driver_Id = A1.users_id)
WHERE A.users_id IS NULL AND A1.users_id IS NULL AND T.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY T.request_at
```
# 解法三
与解法二思路相同。找出被禁止的用户后，不再连接行程表和用户表，直接从行程表中排除掉被被禁止用户的行程记录。

被禁止的用户用子查询：
```
(
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
)
```
行程表中client_id和driver_id都在此子查询结果中的行要剔除掉。
```
SELECT *
FROM trips AS T
WHERE 
T.Client_Id NOT IN (
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
)
AND
T.Driver_Id NOT IN (
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
)
```
补上其它部分：
```
SELECT T.request_at AS `Day`, 
	ROUND(
			SUM(
				IF(T.STATUS = 'completed',0,1)
			)
			/ 
			COUNT(T.STATUS),
			2
	) AS `Cancellation Rate`
FROM trips AS T
WHERE 
T.Client_Id NOT IN (
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
)
AND
T.Driver_Id NOT IN (
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
)
AND T.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY T.request_at
```

文章原先发表在博客上，但是拷贝到这里后格式都没了。
要看得更清晰，以及其它部分题目的题解请参考个人博客。
www.jasonpeng.cn