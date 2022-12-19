```
select a.visited_on
    ,sum(b.amount) amount
    ,round(sum(b.amount)*1.0/7,2) average_amount
from (
    select visited_on,sum(amount) amount
    from Customer
    group by visited_on
) a
left join Customer b on b.visited_on between dateadd(dd,-6,a.visited_on) and a.visited_on
group by a.visited_on
having count(distinct b.visited_on) =7
```
执行用时 :650 ms, 内存消耗 :0B