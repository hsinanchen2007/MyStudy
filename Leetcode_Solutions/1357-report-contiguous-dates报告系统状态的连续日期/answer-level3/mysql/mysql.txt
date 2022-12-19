```
select 
    if(str=1,'succeeded','failed') as period_state ,
    min(date) as start_date,
    max(date) as end_date
from (
    select 
        @diff := @diff+ if(num = 1 , 1,0) as diff,
        date,
        str
    from (
    select 
        case when @str = str and  date_add(@pre,interval 1 day) = date  then @num := @num +1
            when @str:=str then  @num := 1
            else @num := 1
        end as num,
        @pre := date,
        date,
        str
    from (
        select fail_date   as date ,0 as 'str' from Failed  union  select success_date,1 from Succeeded 
    ) s  ,(select @pre:=null,@num:=0,@str := null) s1
    where date between '2019-01-01' and '2019-12-31'
    order by date 
    ) s,(select @diff:=0)  s1
) ys group by diff,str
```
