```
select project_id 
from(
select project_id, ifnull(count(*),0) as num #如果某个项目没有员工，则返回0
from project
group by project_id) as t

where num in
(select max(num) #降序排列比如：3，2，0；考虑存在多个相同的情况：3，3，2，2，0,要先找到最大的num
from(
select project_id, ifnull(count(*),0) as num #如果某个项目没有员工，则返回0
from project
group by project_id) as t
)
```
