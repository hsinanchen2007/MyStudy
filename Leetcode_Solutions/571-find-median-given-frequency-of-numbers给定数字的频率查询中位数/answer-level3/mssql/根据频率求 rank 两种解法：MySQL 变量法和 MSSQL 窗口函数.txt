## MySQL 变量法
```mysql
select
    avg(Number) median
from (
    select
        Number,
        Frequency,
        @sum pre_sum,
        @sum := Frequency + @sum curr_sum
    from 
        Numbers,
        (select @sum := 0) t
    order by Number
) t1 
where 
    t1.pre_sum <= (@sum / 2) and 
    t1.curr_sum >= (@sum / 2)
```
## MSSQL 窗口函数
```mysql
select 
    avg(cast(number as float)) median
from 
    (
        select 
            Number,
            Frequency,
            sum(Frequency) over(order by Number) - Frequency prev_sum,
            sum(Frequency) over(order by Number) curr_sum
        from Numbers
    ) t1,
    (
        select 
            sum(Frequency) total_sum
        from Numbers
    ) t2
where 
    t1.prev_sum <= (cast(t2.total_sum as float) / 2) and 
    t1.curr_sum >= (cast(t2.total_sum as float) / 2)
```

