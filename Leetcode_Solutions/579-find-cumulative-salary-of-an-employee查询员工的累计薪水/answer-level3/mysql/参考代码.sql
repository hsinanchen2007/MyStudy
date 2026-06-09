SELECT A.Id,A.Month,A.Salary
FROM (SELECT E1.Id,E1.Month,E1.Salary + IFNULL(E2.Salary,0) + IFNULL(E3.Salary,0) AS Salary
      FROM Employee AS E1
      LEFT JOIN Employee AS E2 
      ON E1.Id = E2.Id
      AND E1.Month - E2.Month = 1
      LEFT JOIN Employee AS E3
      ON E2.Id = E3.Id
      AND E2.Month - E3.Month = 1) AS A
WHERE (Id,Month) NOT IN (SELECT Id,MAX(Month) 
                         FROM Employee
                         GROUP BY Id)
ORDER BY Id,Month DESC