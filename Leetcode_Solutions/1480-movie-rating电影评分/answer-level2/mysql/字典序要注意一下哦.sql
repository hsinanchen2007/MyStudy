### 解题思路
字典序是指按字典中出现的先后顺序进行排序，写成按id排了就很难受。

### 代码

```mysql
# Write your MySQL query statement below
(
  select u.name as results
  from movie_rating mr left join users u
  on mr.user_id = u.user_id
  group by mr.user_id
  order by count(*) desc,u.name
  limit 1
)
union
(
    select m.title as results
    from movie_rating mr left join movies m
    on mr.movie_id = m.movie_id
    where left(created_at,7) = '2020-02'
    group by m.movie_id
    order by avg(mr.rating) desc, m.title
    limit 1
);
```