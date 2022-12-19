### 解题思路
使用窗口函数。从题中可知，返回前三高工资的所有员工。it部门返回4位员工，薪资为（90000，85000，85000，70000），即对同一部门员工工资不间断排序。应该使用dense_rank()

### 代码

```mssql
/* Write your T-SQL query statement below */
select tt.department,tt.name employee,tt.salary
from
(select e.*,d.name as department,dense_rank() over(partition by e.departmentid order by salary desc) as RN
from employee e,department d
where e.departmentid=d.id) AS tt
where tt.RN<=3
order by department asc,salary desc;
```