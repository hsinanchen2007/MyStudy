```
select post_id,count(sub_id) as number_of_comments
from(
    select distinct a.sub_id as post_id,b.sub_id as sub_id
    from Submissions a left join Submissions b 
    on a.sub_id=b.parent_id
    where a.parent_id is null
) as T
group by post_id;
```
