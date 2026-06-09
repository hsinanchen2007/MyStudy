select sum(I1.TIV_2016) TIV_2016
from insurance I1
where I1.TIV_2015 in (select TIV_2015 from insurance where I1.PID!=PID)
and concat(I1.LAT,I1.LON) not in (select concat(LAT,LON) from insurance where I1.PID!=PID)