```mssql
/* Write your T-SQL query statement below */
SELECT Id, Company, Salary FROM
(SELECT Id, Company, Salary, COUNT(Salary) OVER (PARTITION BY Company) AS CN,
ROW_NUMBER() OVER (PARTITION BY Company ORDER BY Salary) AS RN FROM Employee) T
WHERE RN = (CN+1)/2 OR RN = (CN+2)/2
```