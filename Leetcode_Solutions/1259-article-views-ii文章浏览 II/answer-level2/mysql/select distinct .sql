### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select distinct v.viewer_id as id from Views v inner join 
(select viewer_id, view_date, count(distinct article_id) as total_count from Views
group by viewer_id, view_date having count(distinct article_id)>=2) temp
on v.viewer_id=temp.viewer_id
order by v.viewer_id
```