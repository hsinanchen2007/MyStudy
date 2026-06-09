
```
select s1.Score as Score,count(*) as Rank
from Scores s1 
join 
(select distinct Score from Scores )as s2 
on s1.Score<=s2.Score
group by s1.Id
order by s1.Score Desc
```
