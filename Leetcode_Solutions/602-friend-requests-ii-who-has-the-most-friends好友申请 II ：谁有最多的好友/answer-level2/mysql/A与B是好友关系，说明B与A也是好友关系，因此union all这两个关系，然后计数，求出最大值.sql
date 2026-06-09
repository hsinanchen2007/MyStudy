### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below




select *
from 
(
    select c.requester_id as id,count(c.requester_id) as num
    from
    (
        select requester_id,accepter_id from request_accepted a 
        union all 
        select accepter_id,requester_id from request_accepted b
     ) c
     group by c.requester_id
)res
order by res.num desc
limit 1
```