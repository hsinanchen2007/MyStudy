```
# Write your MySQL query statement below
(select tbl2.name as results
from (select user_id,count(*) as cnt
from Movie_Rating
group by user_id) tbl1
inner join 
Users tbl2
on tbl1.user_id=tbl2.user_id
order by tbl1.cnt desc,tbl2.name
limit 1)
union all
(select tbl5.title
from (select movie_id,avg(rating) as avgrating
from Movie_Rating
where date_format(created_at,'%Y-%m')='2020-02'
group by movie_id) tbl4
inner join 
Movies tbl5
on tbl4.movie_id=tbl5.movie_id
order by tbl4.avgrating desc,tbl5.title
limit 1
)
```
