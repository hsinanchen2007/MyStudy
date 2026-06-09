空值情况考虑，速度高
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET n = N-1;
RETURN (     
   select ifnull((SELECT DISTINCT Salary 
    FROM Employee
    ORDER BY Salary DESC
    LIMIT n,1),null)
  );
END