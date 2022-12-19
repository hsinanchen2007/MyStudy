### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select s.temp.sub_id as post_id, ifnull(count(distinct s.sub_id),0) as number_of_comments from Submissions s right join 
(select distinct sub_id from Submissions 
where parent_id is null) temp 
on s.parent_id=temp.sub_id
group by temp.sub_id
```