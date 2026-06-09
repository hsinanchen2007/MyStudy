### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select name as results from Users inner join 
(select u.user_id from Movie_Rating m
inner join Users u on 
u.user_id=m.user_id
group by m.user_id 
order by count(m.user_id) desc, u.name asc
limit 1) temp
on temp.user_id=Users.user_id
union 
select title as results from Movies inner join 
(select m.movie_id from Movie_Rating m
inner join Movies m_1 on m_1.movie_id=m.movie_id
where created_at between '2020-02-01' and '2020-02-29'
group by m.movie_id
order by avg(rating) desc, title asc
limit 1) temp_1
on temp_1.movie_id=Movies.movie_id


```