#Write your MySQL query statement below
select Id,Company,Salary from(
select 
    Id,Company,Salary,c,
    (@i:=case when @Company=Company then @i+1 else 1 end)pm,
    @Company:=Company
from
    (select Id,e1.Company as Company,Salary,c
    from Employee e1
    join(
        select Company,(count(Salary)+1)/2 as c from Employee
        group by Company) e2
    on e1.Company=e2.Company
    order by Company,Salary) e1,(select @i:=0,@Company:='')t)t
where round(c,0)=pm or round(c-0.5,0)=pm