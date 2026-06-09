方法一：
select distinct a.Email
from Person a,Person b
where a.Email=b.Email
and a.Id<>b.Id;

方法二：
select Email from (
select Email,count(*)
from Person 
group by Email having count(*)>1);