### 解题思路
涉及到排序的问题：使用窗口函数或者复用表
1.将employee表与department表连接，并使用窗口函数对同一部门的员工薪资进行排序
rank() over(partition by e.departmentid order by e.salary desc)
2.从第一步生成的临时表中，选择所要提取的字段。并设置条件排序RN=1；

### 代码

```mssql
/* Write your T-SQL query statement below */
select temp.department,temp.name employee,temp.salary
from
(select e.*,d.name department,
RANK() over(partition by e.departmentid order by salary desc) RN
from employee e inner join department d
on e.departmentid=d.id) temp
where temp.RN=1;
```