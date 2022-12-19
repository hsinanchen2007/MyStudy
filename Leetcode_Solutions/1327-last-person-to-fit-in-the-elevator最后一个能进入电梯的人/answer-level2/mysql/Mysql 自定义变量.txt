```
select 
    person_name        
from (
    select
        person_name,      
        @num:=@num+(@pre:=weight) as num    
    from Queue q,(select @num:=0,@pre:=0)s order by turn asc
)s1 where num<=1000 order by num desc limit 1
```
