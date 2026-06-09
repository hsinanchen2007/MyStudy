执行用时 :285 ms, 在所有 MySQL 提交中击败了95.41%的用户

### 解题思路
* 先用group by去重，得到部门和薪水的所有组合
* 然后用Employee左连接上一步得到的临时表，按员工id分组后，组内关联出多少条e2的记录，即为有多少种薪水金额高于该员工

### 代码

```mysql
# Write your MySQL query statement below
select d.Name 'Department', e.Name 'Employee', e.Salary 'Salary' 
from Employee e 
left join (select Salary, DepartmentId from Employee group by Salary, DepartmentId) e2 
on e.DepartmentId = e2.DepartmentId and e.Salary < e2.Salary
inner join Department d on e.DepartmentId = d.id
group by e.id having count(e2.Salary)<=2
```

按理说，这种场景，如果支持开窗函数话，那个才是标准解，设计出来就是为了解决这类问题的，底层优化肯定更好