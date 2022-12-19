## MySQL 变量排序
```mysql
select 
    t2.Id,
    t2.Company,
    t2.Salary
from 
    (
        select 
            Company,
            count(Id) cnt
        from Employee
        group by Company
    ) t1
    inner join
    (
        select
            e.*,
            case
                when @prev = e.Company then @cnt := @cnt + 1
                when (@prev := e.Company) is not null then @cnt := 1
            end rnk
        from 
            Employee e,
            (
                select 
                    @prev := null,
                    @cnt := 0
            ) t
        order by e.Company, e.Salary
    ) t2
on t1.Company = t2.Company
where
    (t1.cnt + 2) div 2 = t2.rnk or 
    (t1.cnt + 1) div 2 = t2.rnk
```
## MSSQL 窗口函数
```mysql
select
    Id,
    Company,
    Salary
from (
    select 
        *,
        count(Id) over(partition by Company) cnt,
        row_number() over(partition by Company order by Salary) rnk
    from Employee
) t
where 
    rnk = (cnt + 1) / 2 or 
    rnk = (cnt + 2) / 2
```
