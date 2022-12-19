#打个标记，待优化

#最主要的问题就是在如何对连续日期分组的问题上
1、第一我的想法是开窗求前后连续（相隔为1则为连续），但是这样造成了开窗之后增加了这么一列 (1,1,1 1)
（这里假设没有日期限制，为了好举例子）
Failed table:
+-------------------+
| fail_date      other   |
+-------------------+
| 2018-12-28    1    |
| 2018-12-29    1    |
| 2019-01-04    1    |
| 2019-01-05    1    |
+-------------------+
然后我就蒙圈了，一直在考虑这个连续日期的分组问题，显然我想要把2019-01-04和2019-01-05 分在一组，其他连续的类似如此，但是发现做不下去了，分不了组
然后陷入了沉思》。。。。

其实自己以前做过这种题，实在是伤心啊，所以说想问题不要牛角尖，很容易陷进去，然后就一直傻逼了

2、推翻了之前的思考，换思路，我增加了一列rownum，并且开了个窗
+-----------------------------------+
| fail_date      rownum   min(date) |
+-----------------------------------+
| 2018-12-28    1         2019-12-28|
| 2018-12-29    2         2019-12-28|
| 2019-01-04    3         2019-12-28|
| 2019-01-05    4         2019-12-28|
+-----------------------------------+

然后我将表再次变换

+-----------------------------------------------+
| fail_date      fail_date - min(date) - rownum |
+-----------------------------------+
| 2018-12-28     -1|
| 2018-12-29     -1|
| 2019-01-04     4|
| 2019-01-05     4|
+-----------------------------------+
到了这里，这道题就没什么难度了，啊~
不要进入思维陷阱啊，我真的傻逼了，白白耗费一个多小时的时间

这是求连续日期当中的一种方式（有几种方式），只有这种方式能解决这个分组的问题

另外说一句，这个题的字段描述好像和实际的测试用例有点小区别~


```
/* Write your PL/SQL query statement below */
SELECT *
FROM (
	SELECT 'failed' AS period_state, to_char(MIN(fail_date), 'yyyy-MM-dd') AS start_date
		, to_char(MAX(fail_date), 'yyyy-MM-dd') AS end_date
	FROM (
		SELECT a.fail_date, fail_date - minDate - rn AS groupId
		FROM (
			SELECT a.fail_date, rownum AS rn, MIN(fail_date) OVER (ORDER BY fail_date) AS minDate
			FROM Failed a
			WHERE a.fail_date >= '2019-01-01'
				AND a.fail_date <= '2019-12-31'
		) a
	) a
	GROUP BY a.groupId
	UNION ALL
	SELECT 'succeeded' AS period_state, to_char(MIN(success_date), 'yyyy-MM-dd') AS start_date
		, to_char(MAX(success_date), 'yyyy-MM-dd') AS end_date
	FROM (
		SELECT a.success_date, success_date - minDate - rn AS groupId
		FROM (
			SELECT a.success_date, rownum AS rn, MIN(success_date) OVER (ORDER BY success_date) AS minDate
			FROM Succeeded a
			WHERE a.success_date >= '2019-01-01'
				AND a.success_date <= '2019-12-31'
		) a
	) a
	GROUP BY a.groupId
) a
ORDER BY a.start_date
```
