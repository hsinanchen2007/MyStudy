执行用时 :603 ms, 在所有 Oracle 提交中击败了100.00%的用户
select 
    Id,
    Month,
    sum(Salary) over(partition by id order by month desc rows between current row and 2 following) Salary  
from (select 
        Id,
        Month,
        Salary,rank() over(partition by id order by Month desc ) r 
      from Employee) 
where r >=2 
order by id,month desc