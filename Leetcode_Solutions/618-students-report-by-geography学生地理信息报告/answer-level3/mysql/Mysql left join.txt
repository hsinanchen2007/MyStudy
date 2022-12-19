```
select t1.name America,t2.name Asia,t3.name Europe
from
((select name,row_number() over (order by name) as id
from student
where continent = 'America') t1 
left join 
(select name,row_number() over (order by name) as id
from student
where continent = 'Asia') t2 on t1.id = t2.id)  
left join
(select name,row_number() over (order by name) as id
from student
where continent = 'Europe') t3 on t1.id = t3.id
```
两次left join。没有想到第一次left join后的表不用再赋名。