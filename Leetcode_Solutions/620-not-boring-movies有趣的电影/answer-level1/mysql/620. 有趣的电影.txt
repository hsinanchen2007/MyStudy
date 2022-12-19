- 降序排序 order by xx desc
- 奇数 id % 2 = 1
```
# Write your MySQL query statement below

select * 
from cinema
where id % 2 = 1 and description != 'boring'
order by rating desc
```
