### 解题思路
此处撰写解题思路
两级group by + having + 结果去重
### 代码

```mysql
# Write your MySQL query statement below

select distinct viewer_id as id
from Views 
group by viewer_id,view_date  
having count(distinct article_id )>=2
order by id
```