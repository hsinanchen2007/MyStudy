[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

# 解法一
一个事实是数字展开成升序列后，相同数字一定排在一起。

思路：

1. 确定每个数字，在展开后的升序列中，起始和结束下标；
2. 在展开后的升序列中， 中位数的起始和结束下标；
3. 由1和2，筛选出是中位数的行

**注意**，起始下标从0开始，结束下标为开区间。

先算每个数字，在展开后的升序列中，起始下标。

应用排名算法：表left join自连接，group by对数字分组，按数字升序。

再筛选出比每个数字小的所有其它数字的行。将这些行的中频率值相加。其值即为起始下标。

结果命名为A。
```
(
	SELECT N1.NUMBER, SUM(IF(N2.frequency IS NULL,0,N2.frequency)) AS `beg`
	FROM numbers AS N1
	LEFT JOIN numbers AS N2 ON (N1.NUMBER > N2.NUMBER)
	GROUP BY N1.number
	ORDER BY N1.NUMBER
) AS A
```
再算每个数字，在展开后的升序列中，结束下标。

再用排名算法： 表left join自连接，group by对数字分组，按数字升序。

再筛选出比每个数字小于等于的所有其它数字的行。将这些行的中频率值相加。其值即为结束下标，且是开区间。

结果命名为B。
```
(
	SELECT N1.NUMBER, SUM(IF(N2.frequency IS NULL,0,N2.frequency)) AS `end`
	FROM numbers AS N1
	LEFT JOIN numbers AS N2 ON (N1.NUMBER >= N2.NUMBER)
	GROUP BY N1.number
	ORDER BY N1.number
) AS B
```
那么，连接表A和表B，关联于相同的数字。每个数字，在展开后升序列中的位置区间为[beg,end)。
```
SELECT *
FROM 
(
	SELECT N1.NUMBER, SUM(IF(N2.frequency IS NULL,0,N2.frequency)) AS `beg`
	FROM numbers AS N1
	LEFT JOIN numbers AS N2 ON (N1.NUMBER > N2.NUMBER)
	GROUP BY N1.number
	ORDER BY N1.NUMBER
) AS A
JOIN 
(
	SELECT N1.NUMBER, SUM(IF(N2.frequency IS NULL,0,N2.frequency)) AS `end`
	FROM numbers AS N1
	LEFT JOIN numbers AS N2 ON (N1.NUMBER >= N2.NUMBER)
	GROUP BY N1.number
	ORDER BY N1.number
) AS B
	ON (A.NUMBER = B.NUMBER)
```
再算在展开后的升序列中， 中位数的起始和结束下标

数字总数N是偶数时，下标(N-1)/2和N/2位置处为中位数。N是奇数时，下标(N-1)/2为中位数。

数字的频率之和为N。确定中位数区间[beg,beg+cnt+1)，beg从0开始。

beg = (N-1)/2

cnt = 0或1，N为偶数时为1，N为奇数时为0。

结果命名为表C。
```
(
	SELECT FLOOR((SUM(N.frequency)-1)/2) AS `beg`,
        if(SUM(N.frequency)%2=1,0,1) AS `cnt`
	FROM numbers AS N
) AS C
```
第三步，筛出落在中位数区间中的数字

已经有每个数字的位置区间S=[A.beg,B.end)。中位数位置区间T=[beg,beg+cnt+1) 。

易知，区间S和区间T相交位置的数字是中位数。

区间S与区间T的长度大小关系有两种。

第一种，T区间长度 >= S区间长度。

那么，判断区间S与区间T是否相交，逻辑为：
```
if(S的起点落在区间T中 或 S的尾部落在区间T中)
{
    满足此条件的数据行为中位数行
}
```
SQL代码：
```
(
	(C.beg <= A.beg AND A.beg < (C.beg +C.cnt+1)) 
	OR 
	(C.beg < B.END AND B.END <= (C.beg +C.cnt+1))
)
```
第二种，T区间长度 < S区间长度。

那么，判断区间S与区间T是否相交，逻辑为：
```
if(T的起点落在区间S中 或 T的尾部落在区间S中)
{
    满足此条件的数据行为中位数行
}
```
SQL代码：
```
(
	(A.beg <= C.beg AND C.beg < B.end) 
	OR 
	(A.beg < (C.beg+C.cnt+1) AND (C.beg+C.cnt+1) <= B.END)
)
```
合起来，判断中位数的逻辑是：
```
(
	(
		(C.beg <= A.beg AND A.beg < (C.beg +C.cnt+1)) 
		OR 
		(C.beg < B.END AND B.END <= (C.beg +C.cnt+1))
	)
	OR
	(
		(A.beg <= C.beg AND C.beg < B.end) 
		OR 
		(A.beg < (C.beg+C.cnt+1) AND (C.beg+C.cnt+1) <= B.END)
	)
)
```
连接表A，表B和表C，得出中位数的数字：
```
SELECT *
FROM 
(
	SELECT N1.NUMBER, SUM(IF(N2.frequency IS NULL,0,N2.frequency)) AS `beg`
	FROM numbers AS N1
	LEFT JOIN numbers AS N2 ON (N1.NUMBER > N2.NUMBER)
	GROUP BY N1.number
	ORDER BY N1.NUMBER
) AS A
JOIN 
(
	SELECT N1.NUMBER, SUM(IF(N2.frequency IS NULL,0,N2.frequency)) AS `end`
	FROM numbers AS N1
	LEFT JOIN numbers AS N2 ON (N1.NUMBER >= N2.NUMBER)
	GROUP BY N1.number
	ORDER BY N1.number
) AS B
	ON (A.NUMBER = B.NUMBER)
JOIN 
(
	SELECT FLOOR((SUM(N.frequency)-1)/2) AS `beg`, if(SUM(N.frequency)%2=1,0,1) AS `cnt`
	FROM numbers AS N
) AS C
	ON (
			(
				(C.beg <= A.beg AND A.beg < (C.beg +C.cnt+1)) 
				OR 
				(C.beg < B.END AND B.END <= (C.beg +C.cnt+1))
			)
			OR
			(
				(A.beg <= C.beg AND C.beg < B.end) 
				OR 
				(A.beg < (C.beg+C.cnt+1) AND (C.beg+C.cnt+1) <= B.END)
			)
		)
```
在结果集中，

当数字总数N为偶数是，最多有两行数据。

当数字总数N为奇数是，只有一行数据。

因此可知，中位数 = 数据行的数字总和 / 数据总行数 = 数字的平均数
```
SELECT AVG(A.NUMBER) AS `median`
FROM
...
```
综合得出最终逻辑为：
```
SELECT AVG(A.NUMBER) AS `median`
FROM 
(
	SELECT N1.NUMBER, SUM(IF(N2.frequency IS NULL,0,N2.frequency)) AS `beg`
	FROM numbers AS N1
	LEFT JOIN numbers AS N2 ON (N1.NUMBER > N2.NUMBER)
	GROUP BY N1.number
	ORDER BY N1.NUMBER
) AS A
JOIN 
(
	SELECT N1.NUMBER, SUM(IF(N2.frequency IS NULL,0,N2.frequency)) AS `end`
	FROM numbers AS N1
	LEFT JOIN numbers AS N2 ON (N1.NUMBER >= N2.NUMBER)
	GROUP BY N1.number
	ORDER BY N1.number
) AS B
	ON (A.NUMBER = B.NUMBER)
JOIN 
(
	SELECT FLOOR((SUM(N.frequency)-1)/2) AS `beg`, if(SUM(N.frequency)%2=1,0,1) AS `cnt`
	FROM numbers AS N
) AS C
	ON (
			(
				(C.beg <= A.beg AND A.beg < (C.beg +C.cnt+1)) 
				OR 
				(C.beg < B.END AND B.END <= (C.beg +C.cnt+1))
			)
			OR
			(
				(A.beg <= C.beg AND C.beg < B.end) 
				OR 
				(A.beg < (C.beg+C.cnt+1) AND (C.beg+C.cnt+1) <= B.END)
			)
		)
GROUP BY C.cnt
```
# 解法二
先算在展开后的升序列中， 中位数的起始和结束下标

借鉴解法一，逻辑为：
```
(
	SELECT FLOOR((SUM(N.frequency)-1)/2) AS `beg`,
        if(SUM(N.frequency)%2=1,0,1) AS `cnt`
	FROM numbers AS N
) AS B
```
定义用户变量:@fre_sum——数字升序列中频率前缀和，从0开始。
```
(SELECT @fre_sum:=0) AS C
```
连接数字表A，表B和表C，并按照数字升序。
```
(
        SELECT *
	FROM 
	numbers AS A,
	(
		SELECT 
			FLOOR((SUM(N.frequency)-1)/2) AS `beg`, 
			IF(SUM(N.frequency)%2=1,0,1) AS `cnt`
		FROM numbers AS N
	) AS B,
	(SELECT @fre_sum:=0) AS C
	ORDER BY A.number
) AS D
```
再选出中位数的数字。

每个数字的@fre_sum的值，确定了一个区间S=[@fre_sum,@fre_sum+A.frequency)。

只要中位数区间T=[B.beg,B.beg+B.cnt+1)与区间T相交。相交的数字即是中位数。

判断相交的逻辑：
```
if(T的起点落在区间S中 或 T的终点落在区间S中){
    此数字是中位数
}
```
SQL代码：
```
	if(
		@fre_sum<=B.beg AND B.beg < (@fre_sum + A.Frequency),
		1,
		if(
			@fre_sum < (B.beg+B.cnt+1) AND (B.beg+B.cnt+1) <= (@fre_sum + A.Frequency),
			1,
			0
		)
	) AS wanted
```
@fre_sum更新逻辑：
```
@fre_sum:=@fre_sum+A.Frequency AS fre
```
补充上中位数选择逻辑。
```
(
	SELECT A.*,B.*,
	if(
		@fre_sum<=B.beg AND B.beg < (@fre_sum + A.Frequency),
		1,
		if(
			@fre_sum < (B.beg+B.cnt+1) AND (B.beg+B.cnt+1) <= (@fre_sum + A.Frequency),
			1,
			0
		)
	) AS wanted,
	@fre_sum:=@fre_sum+A.Frequency AS fre
	FROM 
	numbers AS A,
	(
		SELECT 
			FLOOR((SUM(N.frequency)-1)/2) AS `beg`, 
			IF(SUM(N.frequency)%2=1,0,1) AS `cnt`
		FROM numbers AS N
	) AS B,
	(SELECT @fre_sum:=0) AS C
	ORDER BY A.number
) AS D
```
从表D中选出wanted=1的数字，并求平均值，为最终结果。
```
SELECT AVG(D.NUMBER) AS `median`
FROM 
(
	SELECT A.*,B.*,
	if(
		@fre_sum<=B.beg AND B.beg < (@fre_sum + A.Frequency),
		1,
		if(
			@fre_sum < (B.beg+B.cnt+1) AND (B.beg+B.cnt+1) <= (@fre_sum + A.Frequency),
			1,
			0
		)
	) AS wanted,
	@fre_sum:=@fre_sum+A.Frequency AS fre
	FROM 
	numbers AS A,
	(
		SELECT 
			FLOOR((SUM(N.frequency)-1)/2) AS `beg`, 
			IF(SUM(N.frequency)%2=1,0,1) AS `cnt`
		FROM numbers AS N
	) AS B,
	(SELECT @fre_sum:=0) AS C
	ORDER BY A.number
) AS D
WHERE wanted = 1
```