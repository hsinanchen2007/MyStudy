select S1.sub_id post_id,count(distinct S2.sub_id)number_of_comments
from Submissions S1 left join Submissions S2
on S1.sub_id=S2.parent_id
where S1.parent_id is null
group by S1.sub_id