```sql []
select  id,  month, sala salary
from
    (select  month,   
            @sa := if(@i = id, salary + if(month-@prem<3, @pre, 0) + if(month-@preprem<3, @prepre, 0), salary) as Sala,  #三个月的累计薪水
            @prepre := if(@i = id, @pre, 0) as prepresa,  #前前行的薪水，可能不是上上个月
            @pre := salary as presa,    #前一行的薪水，可能不是上个月
            @i := id as id,             #前一个id
            @preprem := if(@i = id, @prem, 0) prepremonth, #前前行的月份
            @prem := month as premonth   #前一行的月份
    from employee, (select @sa := 0, @pre := 0, @prepre := 0, @i := null, @prem := 0, @preprem := 0) init
    order by id, month) t
where (id, month) not in       #不包括当前月
            (  
                select id, max(month)
                from employee 
                group by id
            ) 
order by id asc, month desc
;
```
