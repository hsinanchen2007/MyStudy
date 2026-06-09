### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
SELECT Department.Name AS 'Department',
Employee.Name AS 'Employee',
Salary
FROM Employee
JOIN Department
ON Employee.DepartmentId =Department. Id 
WHERE (Employee.DepartmentId ,Salary) in(
        SELECT DepartmentId,MAX(Salary)
        from Employee
        GROUP BY DepartmentId
);

```
思路：
第一，因为存在两个表链接的关系，想到多表查询，需要去理解join，left join 以及left join的用法；使用left join的时候出现了错误，这点有点疑惑；
第二，要去考虑工资最高的情况，可以使用子查询的方式，先查询到工资最高和对应的员工id，使用分组聚合id，接着使用in表明要找的id和最高的薪资。
