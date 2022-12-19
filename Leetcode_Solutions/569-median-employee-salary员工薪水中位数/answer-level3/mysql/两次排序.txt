### 解题思路
1.同公司内，按照Salary分别升序降序排序
2.两次排序结果之差绝对值小于2即为题目所求中位数

### 执行结果
执行用时 :181 ms, 在所有 MySQL 提交中击败了45.32%的用户

### 代码

```mysql
# Write your MySQL query statement below

SELECT Id, Company, Salary
FROM (
	SELECT Id, Company, Salary, rank
		, @rank := if(@last_comp = Company, @rank + 1, 1) AS reverse
		, @last_comp := Company
	FROM (
		SELECT Id, Company, Salary
			, @rank := if(@last_comp = Company, @rank + 1, 1) AS rank
			, @last_comp := Company
		FROM Employee, (
				SELECT @last_comp := NULL, @rank := 0
			) temp1
		ORDER BY Company ASC, Salary ASC, Id ASC
	) a, (
			SELECT @last_comp := NULL, @rank := 0
		) temp2
	ORDER BY Company ASC, Salary DESC, Id DESC
) b
WHERE abs(rank - reverse) < 2
ORDER BY Company, Salary
```