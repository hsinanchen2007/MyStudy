SELECT MAX(Salary) AS SecondHighestSalary 
FROM Employee 
where salary < (
SELECT MAX(Salary) 
FROM Employee
)