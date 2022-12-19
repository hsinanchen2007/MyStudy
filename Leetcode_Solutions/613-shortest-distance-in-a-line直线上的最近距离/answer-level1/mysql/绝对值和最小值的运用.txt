select min(abs(p1.x-p2.x)) as shortest from point as p1,point as p2
where abs(p1.x-p2.x)>0