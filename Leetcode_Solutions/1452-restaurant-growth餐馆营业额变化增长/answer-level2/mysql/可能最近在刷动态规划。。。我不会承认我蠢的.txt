将营业额累加，然后作减法得到7天的营业额
```
select t3.visited_on, 
    if(t4.total is null, t3.total, t3.total - t4.total) as amount,
    round(if(t4.total is null, t3.total / 7, (t3.total - t4.total) / 7), 2) as average_amount 
from (
    select visited_on, @total:=@total+amount total, if(@day<7, @day:=@day+1, @day) day
    from (
        select visited_on, sum(amount) amount
        from Customer
        group by visited_on
    ) t1, (select @day:=0, @total:=0) p1
) t3
left join (
    select visited_on, @total2:=@total2+amount total
    from (
        select visited_on, sum(amount) amount
        from Customer
        group by visited_on
    ) t2, (select @total2:=0) p2
) t4
on datediff(t3.visited_on, t4.visited_on) = 7
where t3.day = 7
order by t3.visited_on
```
