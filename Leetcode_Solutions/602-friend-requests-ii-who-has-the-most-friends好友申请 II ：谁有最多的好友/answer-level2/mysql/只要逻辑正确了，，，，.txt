### 解题思路
耗时这个东西，，，怎么优化？

### 代码

```mysql


select id ,count(*) num 
from (
    select requester_id id 
    from request_accepted
    union all 
    select accepter_id id 
    from request_accepted
) tmp
group by id 
order by num desc
limit 1 

```