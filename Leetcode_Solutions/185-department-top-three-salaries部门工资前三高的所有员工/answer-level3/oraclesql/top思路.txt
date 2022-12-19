### 解题思路
使用排序函数求top算是比较普遍的方法了，注意三种排序开窗函数的区别，rank是允许重复但是总数不变，dense_rank是重复但是总数会增加

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select b.Name as Department,
a.Name as Employee , a.Salary
from
(select
DepartmentId,Name,Salary, dense_rank() over(partition by DepartmentId order by Salary desc) as num
from Employee) a
join Department b 
on a.DepartmentId = b.Id
where a.num <=3
```