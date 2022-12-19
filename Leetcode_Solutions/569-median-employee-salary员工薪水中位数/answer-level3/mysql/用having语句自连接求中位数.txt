SELECT e1.Id, e1.Company, e1.Salary
FROM Employee AS e1, Employee AS e2
WHERE e1.Company = e2.Company
GROUP BY e1.Company, e1.Salary
HAVING 
    SUM(CASE WHEN e1.Salary >= e2.Salary THEN 1 ELSE 0 END) >= COUNT(*)/2
    AND SUM(CASE WHEN e1.Salary <= e2.Salary THEN 1 ELSE 0 END) >= COUNT(*)/2
ORDER BY e1.Company;