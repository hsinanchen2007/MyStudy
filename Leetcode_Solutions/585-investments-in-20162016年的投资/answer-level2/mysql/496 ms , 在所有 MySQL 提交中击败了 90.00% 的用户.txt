select sum(t1.TIV_2016) TIV_2016 
from (select *,CONCAT(lat,lon) as ll from insurance group by ll having count(*) < 2) t1 
join (select * from insurance where pid not in (select pid from insurance group by TIV_2015 having count(*) < 2)) t2 
on t1.pid = t2.pid 