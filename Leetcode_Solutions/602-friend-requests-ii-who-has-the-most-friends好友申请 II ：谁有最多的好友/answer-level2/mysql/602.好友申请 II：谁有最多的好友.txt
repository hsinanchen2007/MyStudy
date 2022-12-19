方法：在题目的假设下，每一条记录说明请求者和接受者好友都+1，所以可以通过`union all`来统一用户。

```MySQL
select id, count(*) num
from 
    (select requester_id id from request_accepted 
    union all
    select accepter_id id from request_accepted) tmp 
group by id
order by count(*) desc
limit 1;
```

