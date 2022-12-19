### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select table1.sub_id as post_id , count(table2.sub_id) as number_of_comments from
(select distinct sub_id,parent_id from Submissions where parent_id is Null) as table1
left join
(select distinct sub_id,parent_id from Submissions where parent_id is not Null) as table2
on table1.sub_id = table2.parent_id
group by table1.sub_id

```