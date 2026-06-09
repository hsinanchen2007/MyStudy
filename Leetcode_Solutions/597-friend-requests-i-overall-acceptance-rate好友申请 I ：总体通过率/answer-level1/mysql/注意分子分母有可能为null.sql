### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select ifnull(round(
        s.rta/f.fdr
        ,2),0.00)as'accept_rate'
from (select count(distinct requester_id,accepter_id) as 'rta'
        from request_accepted
)s,(select count(distinct sender_id,send_to_id) as 'fdr' 
        from friend_request
)f
;
/*
select round(
    ifnull(
    (select count(distinct requester_id, accepter_id) from request_accepted) as A)
    /
    (select count(distinct sender_id, send_to_id) from friend_request) as B),
    0)
, 2) as accept_rate;
*/
```