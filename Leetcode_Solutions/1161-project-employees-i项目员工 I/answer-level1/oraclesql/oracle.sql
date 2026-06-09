```sql
select
    p.project_id,
    cast(avg(e.experience_years) as decimal(10, 2)) as average_years
from project p, employee e
where p.employee_id = e.employee_id
group by p.project_id
```

代码应该没问题，但是显示执行出错。。。莫名其妙
