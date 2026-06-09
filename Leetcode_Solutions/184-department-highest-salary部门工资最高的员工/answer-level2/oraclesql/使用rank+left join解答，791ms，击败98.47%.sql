看到很少有人用oracle进行解答，抛砖引玉一把。。
1.使用rank，而不使用row_number进行排序；
2.Department表left join排序后的中间表，而不反过来，不然有一条测试样例不通过。
附代码：
```sql
---- oracle ----
/* Write your PL/SQL query statement below */
select b.Name as Department,
       t.Name as Employee,
       t.Salary as Salary
from Department b
left join
(
select Name,
       Salary,
       DepartmentId,
       rank() over(partition by DepartmentId order by Salary desc) as rank
from Employee
) t
on t.DepartmentId = b.Id
where t.rank = 1; ---- 791ms
```
