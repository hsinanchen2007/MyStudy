```
select avg(Number) as median from(
    select * from(
        select 
            Number,
            Frequency,
            cast((@sum1:=@sum2) as signed) as sum1,
            @sum2:=Frequency+@sum2 as sum2
        from 
            (select * from Numbers order by Number) n,
            (select @sum1:=0,
             @sum2:=0) t) t) t,(select @mid:=sum(Frequency)/2 from Numbers) m
where 
    if(@mid%1!=0,
       sum1<=@mid and sum2>=@mid,
       (sum1<=floor(@mid) and sum2>=floor(@mid)) or
       (sum1<=ceiling(@mid) and sum2>=ceiling(@mid)))
```
