CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        /* Write your T-SQL query statement below. */
        SELECT NULLIF((
        SELECT b.Salary FROM (
        SELECT ROW_NUMBER() OVER (ORDER BY a.Salary DESC
        ) AS NO,Salary FROM (
        SELECT DISTINCT(Salary) AS Salary FROM Employee)a
        )b WHERE NO = @N),NULL) AS getNthHighestSalary
    );
END