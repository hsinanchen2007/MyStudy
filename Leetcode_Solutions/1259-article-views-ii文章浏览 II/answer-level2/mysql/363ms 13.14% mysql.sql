### 解题思路
用join

### 代码

```mysql
# Write your MySQL query statement below


select distinct v2.viewer_id id
from views v1 left join views v2
on v1.view_date = v2.view_date and v1.viewer_id = v2.viewer_id and v1.article_id <>v2.article_id
where v2.viewer_id is not null
order by v2.viewer_id
```