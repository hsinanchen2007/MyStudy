[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

# 解法一
首先要明确“三个月内”是什么意思？

设当前月为a，则a，a-1，a-2为“三个月内”。

这种“前缀和”问题，通常采用自连接。

先找出每个月的“三个月内”的全部月份。
```
SELECT *
FROM employee AS E1 JOIN employee AS E2 ON (E1.Id = E2.Id AND E1.MONTH >= E2.MONTH and E2.MONTH >= E1.MONTH - 3)
```
其中：
```
E1.MONTH >= E2.MONTH and E2.MONTH >= E1.MONTH - 3
```
表示E1.MONTH的“三个月内”的全部月份。

再计算每个月三个月内的薪水累加和。

group by按id和month分组。计算E2.Salary的累加和。结果命名为A。
```
(
	SELECT E1.Id,E1.MONTH,SUM(E2.Salary) AS `tsalary`
	FROM employee AS E1 JOIN employee AS E2 ON (E1.Id = E2.Id AND E1.MONTH >= E2.MONTH and E2.MONTH >= E1.MONTH - 2)
	GROUP BY E1.Id,E1.MONTH
) AS A
```
又因为不能包括最近一个月的薪水。

其实是要排除最高月份的值。

每个员工的最高月份。group by按id分组，最大月份值。

结果命名为B。
```
(
	SELECT E.Id, MAX(E.MONTH) AS `max_month`
	FROM employee AS E
	GROUP BY E.Id
) AS B
```
结合表A和表B，选出每个员工最高月份之前的值。

结果请按 ‘Id’ 升序，按 ‘Month’ 降序显示 。
```
SELECT A.id,A.month,A.tsalary AS `Salary`
from
(
	SELECT E1.Id,E1.MONTH,SUM(E2.Salary) AS `tsalary`
	FROM employee AS E1 JOIN employee AS E2 ON (E1.Id = E2.Id AND E1.MONTH >= E2.MONTH and E2.MONTH >= E1.MONTH - 2)
	GROUP BY E1.Id,E1.MONTH
) AS A
JOIN 
(
	SELECT E.Id, MAX(E.MONTH) AS `max_month`
	FROM employee AS E
	GROUP BY E.Id
) AS B
	ON (A.Id=B.Id AND A.MONTH < B.max_month)
order by A.id,A.month desc
```
# 解法二
与解法一思路相同，既然只需要连续三个月的值。

干脆三个员工表自连接即可。

又由于1月份，2月份，向前不可能有三个月。

必然要用left join。
```
SELECT *
FROM employee AS E1
LEFT JOIN employee AS E2 ON (E1.Id = E2.Id AND E2.MONTH = E1.MONTH -1)
LEFT JOIN employee AS E3 ON (E3.Id = E2.Id AND E3.MONTH = E2.MONTH -1)
```
再讲三个月的薪水相加。注意到E2.Salary和E3.Salary为NULL时，薪水值为0.

结果命名为A。
```
FROM
(
	SELECT E1.Id,E1.MONTH,(E1.Salary + if(E2.Salary IS NULL,0,E2.Salary) + if(E3.Salary IS NULL,0,E3.Salary)) AS `tsalary`
	FROM employee AS E1
	LEFT JOIN employee AS E2 ON (E1.Id = E2.Id AND E2.MONTH = E1.MONTH -1)
	LEFT JOIN employee AS E3 ON (E3.Id = E2.Id AND E3.MONTH = E2.MONTH -1)
) AS A
```
求最大月份如解法一。
```
(
	SELECT E.Id, MAX(E.MONTH) AS `max_month`
	FROM employee AS E
	GROUP BY E.Id
) AS B
```
之后同解法一，连接表A和表B，过滤掉最大月份值。
```
SELECT A.id,A.month,A.tsalary AS `Salary`
FROM
(
	SELECT E1.Id,E1.MONTH,(E1.Salary + if(E2.Salary IS NULL,0,E2.Salary) + if(E3.Salary IS NULL,0,E3.Salary)) AS `tsalary`
	FROM employee AS E1
	LEFT JOIN employee AS E2 ON (E1.Id = E2.Id AND E2.MONTH = E1.MONTH -1)
	LEFT JOIN employee AS E3 ON (E3.Id = E2.Id AND E3.MONTH = E2.MONTH -1)
) AS A
JOIN 
(
	SELECT E.Id, MAX(E.MONTH) AS `max_month`
	FROM employee AS E
	GROUP BY E.Id
) AS B
	ON (A.Id=B.Id AND A.MONTH < B.max_month)
order by A.id,A.month desc
```
# 解法三
员工表按id升序，再按salary升序。

应用用户变量，可计算三个月内薪水累加和。

定义用户变量：@pre_id——上一行的id，@pre_salary1——前一个月的薪水值，@pre_salary2——前两个月的薪水值。
```
(SELECT @pre_id:= NULL,@pre_salary1:=0,@pre_salary2:=0) AS T
```
每个人，三个月内累计薪水的逻辑：
```
if (员工id != @pre_id){
    三个月内累计薪水 = 员工id的薪水
}else{
    三个月内累计薪水 = 员工id的薪水 + @pre_salary1 + @pre_salary2
}
```
SQL代码：
```
IF(E.Id != @pre_id,
	E.Salary
,
	E.Salary + @pre_salary1 + @pre_salary2
) AS `Salary`
```
用户变量更新逻辑：
```
if (员工id != @pre_id)
{
    @pre_salary2 = 0
}
else{
    @pre_salary2 = @pre_salary1
}

@pre_salary1 = 员工id的薪水
@pre_id = 员工id的id。
```
SQL代码：
```
IF(E.Id != @pre_id,
	E.Salary
,
	E.Salary + @pre_salary1 + @pre_salary2
) AS `Salary`,
if(E.Id != @pre_id,
	@pre_salary2:=0
,
	@pre_salary2:=@pre_salary1
) AS `pre2`,
(@pre_salary1:=E.Salary) AS `pre1`,
@pre_id:=E.Id
```
注意：上述逻辑成立的前提—— 员工表按id升序，再按salary升序。

将上述逻辑合起来，结果命名为表A。
```
(
	SELECT 
		E.Id,
		E.MONTH, 
		IF(E.Id != @pre_id,
			E.Salary
		,
			E.Salary + @pre_salary1 + @pre_salary2
		) AS `Salary`,
		if(E.Id != @pre_id,
			@pre_salary2:=0
		,
			@pre_salary2:=@pre_salary1
		) AS `pre2`,
		(@pre_salary1:=E.Salary) AS `pre1`,
		@pre_id:=E.Id
	FROM employee AS E,
	(SELECT @pre_id:= NULL,@pre_salary1:=0,@pre_salary2:=0) AS T
	ORDER BY E.Id,E.MONTH
) AS A
```
每个员工的最大月份类似解法一。
```
(
	SELECT E.Id, MAX(E.MONTH) AS `max_month`
	FROM employee AS E
	GROUP BY E.Id
) AS B
```
之后同解法一，连接表A和表B，过滤掉最大月份值。
```
SELECT A.Id,A.MONTH,A.salary
FROM
(
	SELECT 
		E.Id,
		E.MONTH, 
		IF(E.Id != @pre_id,
			E.Salary
		,
			E.Salary + @pre_salary1 + @pre_salary2
		) AS `Salary`,
		if(E.Id != @pre_id,
			@pre_salary2:=0
		,
			@pre_salary2:=@pre_salary1
		) AS `pre2`,
		(@pre_salary1:=E.Salary) AS `pre1`,
		@pre_id:=E.Id
	FROM employee AS E,
	(SELECT @pre_id:= NULL,@pre_salary1:=0,@pre_salary2:=0) AS T
	ORDER BY E.Id,E.MONTH
) AS A
JOIN 
(
	SELECT E.Id, MAX(E.MONTH) AS `max_month`
	FROM employee AS E
	GROUP BY E.Id
) AS B
	ON (A.Id=B.Id AND A.MONTH < B.max_month)
order by A.id,A.month desc
```