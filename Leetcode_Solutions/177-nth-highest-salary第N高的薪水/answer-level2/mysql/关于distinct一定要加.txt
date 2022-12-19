CREATE FUNCTION getNthHighestSalary (N INT) RETURNS INT
BEGIN
SET N = N - 1;
RETURN (
	SELECT
		(
			SELECT
				e.salary
			FROM
				employee e
			ORDER BY
				e.salary DESC
			LIMIT N,
			1
		)
);
END
```
这段代码提交上去一直报错，但是运行的时候没问题，原因是因为没有加distinct，如果前两行工资相同，本来应该报null，不加distinct的话，就会将工资相同的第二个取出来，所以不可以，应该去除重复行，所以要加上distinct，像下面这样写
CREATE FUNCTION getNthHighestSalary (N INT) RETURNS INT
BEGIN
SET N = N - 1;
RETURN (
	# Write your MySQL query statement below.
	SELECT
		(
			SELECT DISTINCT
				e.salary
			FROM
				employee e
			ORDER BY
				e.salary DESC
			LIMIT N,
			1
		)
);
END