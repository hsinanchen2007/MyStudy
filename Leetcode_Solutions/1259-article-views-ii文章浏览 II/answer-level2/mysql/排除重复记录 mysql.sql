### 解题思路

### 代码

```mysql
# Write your MySQL query statement below
select distinct v1.viewer_id as id
from (select distinct * from Views) as v1
group by v1.viewer_id, v1.view_date
having count(v1.viewer_id) >= 2
```