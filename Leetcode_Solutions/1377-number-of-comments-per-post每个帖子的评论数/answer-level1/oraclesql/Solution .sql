Solution:

1st: Find the post
```
select distinct sub_id as post_id 
 from Submissions 
 where parent_id is null
```

2nd: Conut the number of comments
```
select parent_id,count(distinct sub_id) as number_of_comments 
 from Submissions 
 where parent_id is not null
 group by parent_id
```

3rd: Take care of the post which has no comments, use 'nvl', and we get the final query
```
select a.post_id,nvl(b.number_of_comments, 0) as number_of_comments from
(select distinct sub_id as post_id 
 from Submissions 
 where parent_id is null) a
left join 
(select parent_id, count(distinct sub_id) as number_of_comments 
 from Submissions 
 where parent_id is not null
 group by parent_id) b
on a.post_id = b.parent_id
order by a.post_id
```

