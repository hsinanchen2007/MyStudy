```
select s1.sub_id as post_id, sum(if(s2.sub_id is null, 0, 1)) as number_of_comments
from (select distinct sub_id from Submissions where parent_Id is null)s1 left join (select distinct * from Submissions where parent_Id is not null) s2
on s1.sub_id = s2.parent_id
group by s1.sub_id
```