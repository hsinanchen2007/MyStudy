
```sql
# Write your MySQL query statement below
select id, movie, description, rating 
from cinema
where description <> 'boring' And id & 1
group by 
    rating DESC
```
