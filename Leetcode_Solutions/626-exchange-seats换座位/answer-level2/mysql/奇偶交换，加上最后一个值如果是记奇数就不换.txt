### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select case when mod(id,2)=0 then id-1 
            when id=(select max(t.id) from seat t ) then id
            else id+1 end as id 
,student
from seat
order by id 
```