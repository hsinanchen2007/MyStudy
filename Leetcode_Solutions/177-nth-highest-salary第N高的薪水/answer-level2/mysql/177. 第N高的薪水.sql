将 Salary **去重**并**从低到高排序**，要求返回第 n 高，用 limit 语法返回 limit n-1,1 即可，可能存在 null，用临时表查询即可
```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE P INT;
  SET P = N-1;
  RETURN (
      select(
        SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT P,1
      )
  );
END
```