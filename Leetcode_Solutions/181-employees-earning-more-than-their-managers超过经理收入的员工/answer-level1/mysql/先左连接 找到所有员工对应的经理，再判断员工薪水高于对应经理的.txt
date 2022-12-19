### 解题思路
先左连接 找到所有员工对应的经理，再判断员工薪水高于对应经理的

### 代码

```mysql
# Write your MySQL query statement below

select e1.Name as Employee 
from Employee e1 left join Employee e2
on e1.ManagerId = e2.ID
where e1.Salary >e2.Salary
```