看了看官方的题解。

    where 3 >
    (
        select count(distinct e2.Salary)
        from Employee e2
        where e2.Salary > e1.Salary
    )

主要思路是对于查询到的每一行记录，查找是否有两条大于此记录的信息。

结果当然是可行的，但是我们每查询一条记录都要重新对整张表再次查询这就造成了数据库资源的浪费。
改进一下思路：先查询每个部门的前三高的薪资，将它们单独生成一个表，然后和主表关联。
```
    #按部门分组并排序
SELECT Salary,
       (CASE WHEN @depId = DepartmentId THEN @rownum := @rownum + 1 
        ELSE  @rownum := 1 END)AS num,
       (@depId := DepartmentId)AS dep 
       FROM (SELECT DISTINCT Salary,
                             DepartmentId 
            FROM Employee  ORDER BY DepartmentId,Salary DESC)AS T1,
            (SELECT @rownum:= 0,
                    @depId := (SELECT Id FROM Department ORDER BY Id LIMIT 0,1)
            )AS T2
```
最终代码：
```
SELECT Department.Name AS Department,
       T4.Name AS Employee,
       T4.Salary AS Salary
       FROM
(SELECT Employee.Name AS Name,
        Employee.Salary AS Salary,
        T3.dep AS dep
       FROM 
(SELECT Salary,
       (CASE WHEN @depId = DepartmentId THEN @rownum := @rownum + 1 
        ELSE  @rownum := 1 END)AS num,
       (@depId := DepartmentId)AS dep 
       FROM (SELECT DISTINCT Salary,
                             DepartmentId 
            FROM Employee  ORDER BY DepartmentId,Salary DESC)AS T1,
            (SELECT @rownum:= 0,
                    @depId := (SELECT Id FROM Department ORDER BY Id LIMIT 0,1)
            )AS T2 )AS T3  JOIN Employee ON 
                        Employee.Salary = T3.Salary AND
                        Employee.DepartmentId = T3.dep 
        WHERE T3.num <= 3 )AS T4 JOIN Department ON Department.Id = T4.dep 
        ORDER BY Department,Salary DESC
```




