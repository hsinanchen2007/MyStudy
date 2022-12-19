### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select e3.Name as Department,e1.Name as Employee,e1.Salary from Employee as e1,Employee as e2,Department as e3
where e1.DepartmentId=e2.DepartmentId and e1.Salary<=e2.Salary and e1.DepartmentId=e3.Id
group by e1.Name having count(distinct(e2.Salary))<=3 order by Department ,e1.Salary desc
```