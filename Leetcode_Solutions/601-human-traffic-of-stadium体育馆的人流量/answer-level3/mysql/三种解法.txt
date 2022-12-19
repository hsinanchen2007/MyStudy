[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

# 解法一
先将哪些连续三天客流量都>=100的行找出来。

表三次连接。结果命名为表A。
```
(
	SELECT S1.id AS `id1`,S2.id AS `id2`,S3.id AS `id3`
	FROM stadium AS S1
	JOIN stadium AS S2 ON(S1.id +1 = S2.id AND S1.people >=100 AND S2.people >=100)
	JOIN stadium AS S3 ON(S2.id +1 = S3.id AND S2.people >=100 AND S3.people >=100)
) AS A
```
那么，id1，id2，id3都是满足条件的行号。

与表Stadium连接。取出id1或id2或id3对应的行，但可能有些行重复取，要去重。
```
SELECT DISTINCT S.*
FROM 
(
	SELECT S1.id AS `id1`,S2.id AS `id2`,S3.id AS `id3`
	FROM stadium AS S1
	JOIN stadium AS S2 ON(S1.id +1 = S2.id AND S1.people >=100 AND S2.people >=100)
	JOIN stadium AS S3 ON(S2.id +1 = S3.id AND S2.people >=100 AND S3.people >=100)
) AS A
JOIN stadium AS S ON(A.id1 = S.id OR A.id2=S.id OR A.id3=S.id)
```
# 解法二
对每一行A，如果A的前两行的客流量都>=100，或者A的前一行或后一行的客流量都>=100，或者 A的后两行的客流量都>=100 。那么，行A就是结果中的一条。
```
SELECT *
FROM stadium AS S1
WHERE S1.people >= 100 AND 
(
	2=(
		SELECT COUNT(*)
		FROM stadium AS S
		WHERE S.people >= 100 AND (S.id = S1.id-1 OR S.id = S1.id-2)
	) OR 
	2=(
		SELECT COUNT(*)
		FROM stadium AS S
		WHERE S.people >= 100 AND (S.id = S1.id-1 OR S.id = S1.id+1)
	) OR 
	2=(
		SELECT COUNT(*)
		FROM stadium AS S
		WHERE S.people >= 100 AND (S.id = S1.id+1 OR S.id = S1.id+2)
	)
)
```
A的前两行的客流量都>=100，逻辑如下：
```
2=(
	SELECT COUNT(*)
	FROM stadium AS S
	WHERE S.people >= 100 AND (S.id = S1.id-1 OR S.id = S1.id-2)
)
```
A的前一行或后一行的客流量都>=100，逻辑如下：
```
2=(
	SELECT COUNT(*)
	FROM stadium AS S
	WHERE S.people >= 100 AND (S.id = S1.id-1 OR S.id = S1.id+1)
)
```
A的后两行的客流量都>=100，逻辑如下：
```
2=(
	SELECT COUNT(*)
	FROM stadium AS S
	WHERE S.people >= 100 AND (S.id = S1.id+1 OR S.id = S1.id+2)
)
```
# 解法三
与解法一思路相近。

表自叉积三次。

筛选出客流量>=100，并且三个id依次加1的行。
```
SELECT DISTINCT S1.*
FROM stadium AS S1,stadium AS S2,stadium AS S3
WHERE S1.people>=100 AND S2.people>=100 AND S3.people>=100 AND (
	S1.id +1 = S2.id AND S1.id+2=S3.id OR
	S1.id +1 = S2.id AND S1.id-1=S3.id OR
	S1.id -1 = S2.id AND S1.id-2=S3.id
)
ORDER BY S1.id
```