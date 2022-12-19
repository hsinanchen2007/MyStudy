### 解题思路
两个筛选，一个排序

### 代码

```mysql
select id,movie,description,rating
from cinema
where id%2!=0
and description not in ('boring')
order by rating desc;
```