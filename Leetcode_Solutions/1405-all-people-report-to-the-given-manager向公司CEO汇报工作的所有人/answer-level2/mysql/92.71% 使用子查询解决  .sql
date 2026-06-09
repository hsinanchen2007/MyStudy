### 解题思路
1.理清表结构，单表的一对一
2.问题中，最多包含三层嵌套，那么就有三个条件：
 1.找出manager_id=1的员工(除去ceo)
 2.在第一个的条件上，找出manager_id=（1条件查询出来的结果中的employee_id）（2层间接）
 3.在2条件结果中筛选，同2（3层间接）

### 代码

```mysql
# Write your MySQL query statement below
select e.employee_id
from Employees e
where e.manager_id=1 and e.employee_id != 1
or e.manager_id in (
    select employee_id from Employees e1 where e1.manager_id=1 and e1.employee_id != 1
)
or e.manager_id in(
    select employee_id from Employees e2 where 
    e2.manager_id in (
    select employee_id from Employees e3 where e3.manager_id=1 and e3.employee_id != 1
)
)
```