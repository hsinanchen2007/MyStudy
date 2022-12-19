![捕获.PNG](https://pic.leetcode-cn.com/8a583695b0451ad597e909f9c229b80e8d5dde82875067d07f86c73e0eba37ba-%E6%8D%95%E8%8E%B7.PNG)


select sum(case when t3.TIV_2015 is not null then t2.TIV_2016 else 0 end) TIV_2016 

from(select TIV_2015 from insurance 
     group by TIV_2015 
     having count(TIV_2015)>1)t3

right join (select * from insurance
     group by LAT, LON
     having count(LAT) = 1 and count(LON) = 1) t2

on t2.TIV_2015=t3.TIV_2015