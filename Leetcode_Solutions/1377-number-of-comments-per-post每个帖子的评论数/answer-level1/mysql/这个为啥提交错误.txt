select distinct sub_id post_id,ifnull(num,'0') number_of_comments
from
(select distinct sub_id from Submissions 
where parent_id is null)s
left join
(
    select parent_id,count(distinct sub_id) num
from Submissions
group by parent_id  
)a
ON s.sub_id=a.parent_id