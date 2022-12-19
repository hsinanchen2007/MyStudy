SELECT MAX(t1.Salary) AS SecondHighestSalary
FROM
(
    SELECT *
    FROM Employee
) t1
INNER JOIN
(
    SELECT MAX(Salary) AS Salary
    FROM Employee
) t2
ON t1.Salary < t2.Salary