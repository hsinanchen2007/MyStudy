select round(sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)),2) shortest
from point_2d P1,point_2d P2
where (p1.x!=p2.x || p1.y!=p2.y)
order by shortest limit 1