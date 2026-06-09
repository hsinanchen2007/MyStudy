select c.id,
c.movie,
c.description,
c.rating
from cinema c
where mod(id,2)=1 and 
c.description not like '%boring%' 
order by c.rating desc;

mod(id,2)=1 求余函数 确定奇数id