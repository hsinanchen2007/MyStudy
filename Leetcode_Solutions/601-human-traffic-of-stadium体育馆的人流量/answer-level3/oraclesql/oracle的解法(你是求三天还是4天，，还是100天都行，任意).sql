*这个题我的思路归结以下几点：（mysql的解法，我思路差不多，主要是mysql开窗比较麻烦，低版本不支持开窗，需要多些代码，其实都差不多，我觉得oracle方便些我就用oracle语法写了）*

1. 开窗求连续范围（每一条记录就是一个范围，仔细看开窗，我并没有partition by）
`    例如：存在一个这样的id为1,2,3,4,5，那么**开窗按照日期排序的顺序假定还是按照这个顺序，便于说明**，现在求每一条顺序记录 与它递增相隔1个记录的那个记录的visit_date （按照题意就是三行连续的记录），也就是比如id 1，就要知道 id 3的visit_date ，id 2 就要知道 id 4的visit_date ...以此类推（ps:请注意前面我加粗的地方，id其实就是 实际上的日期，我只是假设他们的顺序排序后一样，便于写，这里打字我就达成了id，**其实它是日期顺序排序的记录**，全部题解说明你就把id看做一个日期递增排序的就行了）`
2. 求出了连续范围之后，**需要剔除不符合条件的范围记录**
    `第一种情况: 比如 id = 4 这条记录，他的后面没有和他相隔1个记录单位的记录，（隔了一个id=5，所以取id=6，但是我们只有5个记录），所以需要干掉这类型的记录，id = 5 也是这种情况，所以第一个条件就是a.nextDataIsNotNull
    第二种情况：如果每个范围中的记录，有一个包含了人流量小于100的记录，那么这个范围全部失效（这里需要注意的一点，就是我们不能根据小于100这个条件就认为他周围（连续三行记录，正负都可）不满足条件，需要从我们的连续范围中根据每个范围是否满足去判断，不然会漏掉数据）,用一个子查询取找，如果这个范围存在这样的记录，就直接剔除`
3. 剔除掉不符合条件的范围，通过范围关联源表记录即可，范围可能有重叠，所以需要去重
```
/* Write your PL/SQL query statement below */
SELECT DISTINCT b.id, to_char(b.visit_date,'yyyy-MM-dd') as visit_date , b.people
FROM (
	SELECT a.*
	FROM (
		SELECT a.*, lead(visit_date, 2) OVER (ORDER BY visit_date) AS nextDate
		FROM stadium a
	) a
	WHERE a.nextDate IS NOT NULL and 0 =(select count(*) from stadium 
    where a.visit_date <= visit_date and a.nextDate >=visit_date and people <100)
) a
	JOIN stadium b
	ON b.visit_date >= a.visit_date
		AND b.visit_date <= a.nextDate
ORDER BY b.id
```
