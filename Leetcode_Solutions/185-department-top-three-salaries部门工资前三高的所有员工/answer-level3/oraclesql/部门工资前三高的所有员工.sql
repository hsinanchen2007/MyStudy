使用dense_rank给每个部门工资做desc排序
```
select Department,Employee,Salary from (
select b.name as Department,a.name as Employee,a.Salary,dense_rank() over(partition by a.DepartmentId order by a.Salary desc) as rn
from Employee a
join Department b on a.DepartmentId=b.id
    )where rn<=3
```

希望可以得到大佬指教~
