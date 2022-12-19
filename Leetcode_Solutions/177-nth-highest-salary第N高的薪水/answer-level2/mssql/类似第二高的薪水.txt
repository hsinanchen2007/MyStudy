CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        SELECT
	        Salary  AS SecondHighestSalary
        FROM
	    (
		    SELECT
			    Salary,
			    row_number () OVER (ORDER BY Salary DESC) AS rn
		    FROM
			    (SELECT DISTINCT Salary FROM
			    Employee) g
	    ) a
        WHERE
	        a.rn = @N 
    );
END