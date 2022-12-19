### 解题思路
两个考点：
	1.联表查询出正确的结果
	2.给列起别名

### 代码

```mysql
SELECT
	e1.NAME AS 'employee' 
FROM
	employee AS e1
	JOIN employee AS e2 ON e1.ManagerId = e2.id 
WHERE
	e1.Salary > e2.Salary;
```