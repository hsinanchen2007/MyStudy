先统计不同公司的人数
```mysql []
select 
    company, count(*) as rank   
from 
    employee
group by 
    company 
```
再对每个公司，按内部工资排名
```mysql []
select 
    *, @r := if(@cpy = company, @r + 1, 1) as rank, @cpy := company   #按公司，根据工资排名
from 
    employee, (select @r := 0, @cpy := null) init
order by 
    company, salary
```
整合一起，取排名位于中位数的
```mysql []
select 
    t3.id, t3.company, t3.salary
from 
    (   select 
            *, @r := if(@cpy = company, @r + 1, 1) as rank, @cpy := company   #按公司，根据工资排名
        from 
            employee, (select @r := 0, @cpy := null) init
        order by 
            company, salary
    ) t3
join
    (   select company, count(*) as rank   #统计公司的人数
        from employee
        group by company 
    ) t2
on 
    (t3.company = t2.company and (t3.rank = t2.rank div 2 + 1 or (t2.rank mod 2 = 0 and t3.rank = t2.rank div 2)))
;    #取排名处于公司中位数，分总数为奇数和偶数两种情况
```
