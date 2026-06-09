### 解题思路
常规思路吧，先把Department表join进去，然后按Department分组，得到每个部门最高的薪资。然后多表查询得到和最高薪资对的上的雇员名字。

### 代码

```mysql
# Write your MySQL query statement below
SELECT Department,e.Name as Employee,Sa as Salary FROM
(SELECT a.DepartmentId as idd,b.Name as Department,max(a.Salary) as Sa FROM Employee as a 
join Department as b on a.DepartmentId = b.Id 
group by Department) as t,Employee as e
where e.Salary=t.Sa and e.DepartmentId=t.idd
;
```