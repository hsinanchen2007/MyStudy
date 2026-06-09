先把按照gender,day把每天的分数按照性别查出来:
```
select gender,day,sum(score_points) as dayTotal
from Scores
group by gender,day
order by gender,day
```
因为要按照日期累加,所以我使用了变量来记录,性别一样的按照日期累加,性别不一样的重置:
```
select gender,day,
cast(if(@prev = gender,@score := @score + dayTotal,@score := dayTotal) as unsigned) as total ,
@prev := gender as prev
from 
(select gender,day,sum(score_points) as dayTotal
from Scores
group by gender,day
order by gender,day) as t1,(select @prev := null,@score := 0) as init
```
最后按照要求的字段返回,完整的sql如下:
```
select gender,day,total
from 
(select gender,day,
cast(if(@prev = gender,@score := @score + dayTotal,@score := dayTotal) as unsigned) as total ,
@prev := gender as prev
from 
(select gender,day,sum(score_points) as dayTotal
from Scores
group by gender,day
order by gender,day) as t1,(select @prev := null,@score := 0) as init) as t2
```
