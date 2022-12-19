### 解题思路
此处撰写解题思路

### 代码

```mysql
SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
	)
```


原来自己写未考虑到薪资一样也显示问题，所以考虑欠缺，官方给的解决方案很棒。
1. 先使用连接将两个表连接起来
2. 然后根据部门进行分组得到部门最高薪资人员
3. 使用in作为条件，in里面可以放置多组条件