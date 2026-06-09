### 解题思路
首先 我想找出每个部门前三高的薪水数值
我employee 表去重
并按 部门id 升序 与 薪水 降序 排序
然后
		(
			CASE
			WHEN @temp = departmentId THEN
				@a := @a + 1
			WHEN @temp := departmentId THEN
				@a := 0
			ELSE
				@a := 0
			end
		) AS mark
这样把序号标起
只需要筛选 mark in (0,1,2)
就得到每个部门和部门前三高的薪水数了

### 代码

```mysql
SELECT DISTINCT
	d.`Name` AS Department,
	e.`Name` AS Employee,
	e.Salary AS Salary
FROM
	employee AS e
INNER JOIN department AS d ON e.DepartmentId = d.Id
INNER JOIN (
	SELECT
		DepartmentId,
		Salary,
		(
			CASE
			WHEN @temp = departmentId THEN
				@a := @a + 1
			WHEN @temp := departmentId THEN
				@a := 0
			ELSE
				@a := 0
			end
		) AS mark

	FROM
		(
			SELECT DISTINCT
				DepartmentId,
				Salary
			FROM
				employee
			ORDER BY
				DepartmentId ASC,
				Salary DESC
		) temp,
		(SELECT @a := 0 ,@temp := NULL) r
) AS sar ON sar.Salary = e.Salary
AND sar.DepartmentId = e.DepartmentId
AND mark IN (0, 1, 2)
```