```
CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN

        /* Write your T-SQL query statement below. */

        SET @N = @N - 1; 
        IF @N < 0
            RETURN NULL;

        DECLARE @intReturn as INT;
        
        SELECT @intReturn = MAX(Salary)
        FROM Employee
        WHERE Salary NOT IN (SELECT DISTINCT TOP (@N) Salary FROM Employee ORDER BY Salary DESC);

        RETURN @intReturn;

END
```
1，查第几，先把前面的数据排除，前面有 @N - 1 个数据
2，前面的数据，用TOP 和 ORDER BY DESC 选出，DISTINCT 防止重复
3，排除用的是 NOT IN 
4，最后直接选出 MAX() 赋值，RETURN