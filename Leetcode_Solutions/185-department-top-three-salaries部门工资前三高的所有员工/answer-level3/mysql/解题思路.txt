### 执行用时
350 ms

### 解题思路
1.排序 
```
Department asc,Salary DESC
```
2.计算排名 
```
# 所在部门第一次出现，排名第一
WHEN e.DepartmentId <> @last_d THEN @rank := 1
# 相同部门，工资与上一位相等，排名不变
WHEN e.DepartmentId = @last_d AND e.Salary = @last_S THEN @rank
# 相同部门，工资比上一位小，排名+1
WHEN e.DepartmentId = @last_d AND e.Salary < @last_S THEN @rank := @rank + 1
```
3.筛选排名前三，关联部门信息
```
WHERE b.rank <= 3
```
### 代码

```mysql
# Write your MySQL query statement below
SELECT d.Name AS Department, b.Name AS Employee, b.Salary AS Salary
FROM (
	SELECT e.Name, e.Salary, e.DepartmentId
		, CASE 
			WHEN e.DepartmentId <> @last_d THEN @rank := 1
			WHEN e.DepartmentId = @last_d
			AND e.Salary = @last_S THEN @rank
			WHEN e.DepartmentId = @last_d
			AND e.Salary < @last_S THEN @rank := @rank + 1
		END AS rank, @last_S := e.Salary, @last_d := e.DepartmentId
	FROM Employee e, (
			SELECT @last_S := 0, @rank := 0
				, @last_d := 0
		) tvs
	ORDER BY e.DepartmentId ASC, e.Salary DESC
) b
	JOIN Department d ON b.DepartmentId = d.Id
WHERE b.rank <= 3
```