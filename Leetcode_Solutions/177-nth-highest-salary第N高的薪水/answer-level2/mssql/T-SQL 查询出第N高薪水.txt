CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        /* Write your T-SQL query statement below. */
       SELECT
	salary AS secondhighestsalary 
FROM
	( SELECT DISTINCT salary FROM employee ) tb 
ORDER BY
	salary DESC OFFSET @N-1 rows FETCH next 1 rows only
    );
END