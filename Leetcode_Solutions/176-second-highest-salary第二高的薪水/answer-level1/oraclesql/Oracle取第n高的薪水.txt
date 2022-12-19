需要取第n高的薪水直接替换 rank = n
```
select case when odr = 1 then Salary else null end as SecondHighestSalary
from(
    select Salary, case when rank = 2 then 1 else 0 end as odr
    from(select Salary, dense_rank() over(order by Salary desc) rank from Employee) t
    order by odr desc
    ) b
where rownum <= 1
;
```

