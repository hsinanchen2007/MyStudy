select distinct Num as ConsecutiveNums
from (select Num, 
        @count:=if(@pre=Num,@count+1,1) as count, 
        @pre:=Num 
        from Logs, 
        (select @pre:=null,@count:=0) r 
        ) t 
where t.count >= 3