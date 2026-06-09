SELECT a.Department,a.Name AS Employee,a.Salary FROM (
SELECT DENSE_RANK()OVER(PARTITION BY b.Name ORDER BY A.Salary DESC) AS Dense_Rank ,
		A.Id,A.Name,A.Salary,A.DepartmentId,B.Name AS Department
FROM Employee AS A INNER JOIN Department AS B ON B.Id = A.DepartmentId)a
WHERE a.Dense_Rank <=3