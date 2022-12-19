select avg(Number) as median from(
    select 
        Number,
        Frequency,
        @sum as sum1,
        @sum:=Frequency+@sum as sum2
    from Numbers,(select @sum:=0) t
    order by Number
) t
where if(@sum&1, 
        sum1<=floor(@sum/2) and sum2>floor(@sum/2),
        sum1<=(@sum/2) and sum2>=(@sum/2))