### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select id,movie,description,rating
from
cinema
where description!= 'boring'
and mod(id,2) != 0
order by rating desc 
```