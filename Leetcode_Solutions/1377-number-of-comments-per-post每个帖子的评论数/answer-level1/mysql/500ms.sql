# Write your MySQL query statement below
select post_id,if(number_of_comments is NULL,0,number_of_comments) as number_of_comments
from(
    select distinct sub_id as post_id,n as number_of_comments 
    from Submissions left join (
        select parent_id as p,count(sub_id) as n 
        from
        (select distinct parent_id,sub_id 
         from Submissions) t
        group by parent_id) t 
    on Submissions.sub_id=t.p
    where Submissions.parent_id is null) t
order by post_id asc;