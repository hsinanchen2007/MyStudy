```
-- 查看员工表
SELECT
	* 
FROM
	employee;
	
-- 查看部门表
SELECT
	* 
FROM
	department;
	
-- 每个部门的最大薪水
SELECT
	DepartmentId,
	MAX( Salary ) 
FROM
	Employee 
GROUP BY
	DepartmentId;
	
-- 连接员工表和部门表
SELECT
	* 
FROM
	Employee
	JOIN department ON Employee.DepartmentId = Department.Id;

-- 加上前面那个部门薪水最高的表过滤一下
SELECT
	* 
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Employee.Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
	)
;

	
	
-- 列名
SELECT
	Department.Name as Department,
	Employee.Name as Employee,
	Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Employee.Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
	)
;




```




