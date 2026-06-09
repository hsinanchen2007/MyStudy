### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
(select u.name `results` from Users u left join Movie_Rating m on u.user_id = m.user_id group by m.user_id order by count(m.user_id) desc,u.name asc limit 1)
union
(select m.title `results` from Movies m left join Movie_Rating mr on m.movie_id = mr.movie_id where created_at between '2020-02-01' and '2020-02-29' group by mr.movie_id order by avg(mr.rating) desc,m.title asc limit 1)

```