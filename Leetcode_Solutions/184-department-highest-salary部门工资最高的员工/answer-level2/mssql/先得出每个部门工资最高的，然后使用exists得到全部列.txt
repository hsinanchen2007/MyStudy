
SELECT t1.Name Department,t.Name Employee,t.Salary FROM Employee t 
LEFT JOIN Department t1 ON t.DepartmentId=t1.Id
WHERE EXISTS (
SELECT * FROM (
SELECT MAX(Salary)Salary,DepartmentId FROM Employee GROUP BY DepartmentId)t1 WHERE t.Salary=t1.Salary AND t.DepartmentId=t1.DepartmentId)
and t1.Name is not null