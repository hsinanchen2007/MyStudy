select l1.num as `ConsecutiveNums`
from logs l1 join logs l2 on l2.id between l1.id-1 and l1.id+1 and l1.num=l2.num
group by l1.id
having count(*)>=3