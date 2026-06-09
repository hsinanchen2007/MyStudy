### 解题思路
第二种参考官方的了，
第一种实现了，但是没有完全匹配。 具体思路  先联查降序，再分组，子查询要加limit，否则查询出来数据不对

### 代码

```mysql
# Write your MySQL query statement below

#select tmp.* from (
#select b.Name as Department,a.Name as Employee,a.Salary   from Employee as a left #join Department b on a.DepartmentId=b.Id order by a.Salary desc limit 10
#) tmp group by  tmp.Department;

select b.Name as Department,a.Name as Employee,a.Salary  from Employee a ,Department b  where a.DepartmentId=b.Id
and (a.DepartmentId,a.Salary) 
in 
(
SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
);

```