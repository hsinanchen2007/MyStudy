```
# Write your MySQL query statement below
select t1.sub_id as post_id,ifnull(t2.cnt,0) as number_of_comments
from 
(select distinct sub_id from Submissions where parent_id is Null) t1
left join 
(select s2.sub_id,count(distinct s1.sub_id) as cnt
from Submissions s1 inner join Submissions s2
on s1.parent_id=s2.sub_id 
group by s2.sub_id) t2
on t1.sub_id=t2.sub_id
order by t1.sub_id
```
