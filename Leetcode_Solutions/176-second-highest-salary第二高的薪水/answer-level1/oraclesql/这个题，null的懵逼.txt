题简单，就是需要返回null的那一刻比较蒙蔽，看了下第一个大佬对于加括号的评论，没想到还真的能用
```
SELECT (
		SELECT nvl(Salary, NULL) AS SecondHighestSalary
		FROM (
			SELECT Salary, rownum AS no
			FROM (
				SELECT Salary
				FROM Employee
				GROUP BY Salary
				ORDER BY Salary DESC
			)
		) a
		WHERE no = 2
	) AS SecondHighestSalary
FROM dual
```
