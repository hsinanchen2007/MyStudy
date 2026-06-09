### 解题思路
1.员工表自连求前三的工资，因为是求前三  所以 (select count(distinct e2.salary) from employee e2 where e2.salary>e1.salary) <3 ,因为是同部门的，比较工资大小的时候需要加条件 e1.departmentid=e2.departmentid
2.1的结果连接（join）部门表，查出所有字段

### 代码

```mysql
# Write your MySQL query statement below
SELECT
	d.name as Department,
	e1. NAME as Employee,
	e1.salary as Salary
FROM
	employee e1 JOIN department d ON d.id=e1.departmentid
WHERE
	(
		SELECT
			COUNT(DISTINCT e2.salary)
		FROM
			employee e2
		WHERE
			e2.salary > e1.salary
		AND e1.departmentid = e2.departmentid
	) < 3
```