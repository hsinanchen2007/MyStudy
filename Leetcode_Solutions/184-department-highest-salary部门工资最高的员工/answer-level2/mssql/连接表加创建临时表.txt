### 解题思路
第一次我直接连接表分组得最高薪水错了，因为最高薪水可能有好几个人，所以首先分组我们得到每个部门最高薪水是多少建立一个临时表，然后再连接Employee表连接条件就是哪个员工是最高薪水和部门号相等最后连接Department表得到部门名字

### 代码

```mssql
/* Write your T-SQL query statement below */
SELECT d.Name AS Department, e.Name AS Employee, e.Salary AS Salary
FROM(SELECT MAX(Salary) AS Salary, DepartmentId FROM Employee GROUP BY DepartmentId) AS a 
JOIN Employee AS e ON a.DepartmentId = e.DepartmentId AND a.Salary = e.Salary
JOIN Department AS d ON e.DepartmentId = d.Id
```