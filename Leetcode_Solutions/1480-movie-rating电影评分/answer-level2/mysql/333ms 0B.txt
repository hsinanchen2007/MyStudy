```
(select name results
from Movie_Rating natural join Users
group by Users.user_id
order by count(*) desc, name asc
limit 1)
union
(select Movies.title results
from Movie_Rating natural join Movies 
where month(created_at)='2'
group by Movies.movie_id
order by avg(rating) desc, title asc
limit 1)
```

