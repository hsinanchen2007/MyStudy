```
select 
    Salary as  SecondHighestSalary  
from (
    select Salary ,if(max(num) <2,true,false)  from (
        select 
        Salary,@num :=@num +(@pev<>@pev:=Salary) as num 
        from  Employee e ,(select @num:=0,@pev:=-1)b 
    order by Salary desc)t
 where num =2)s 

```
