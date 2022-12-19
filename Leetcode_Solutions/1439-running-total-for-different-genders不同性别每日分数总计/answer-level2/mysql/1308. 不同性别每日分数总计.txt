1.结果根据gender和day分组,total记录的是before本记录的所有同性别的和

```
select 
    B.gender,B.day,sum(A.score_points) as total 
from 
    Scores A,Scores B
where 
    A.gender = B.gender
and 
    A.day <= B.day
group by 
    B.gender,B.day
```
